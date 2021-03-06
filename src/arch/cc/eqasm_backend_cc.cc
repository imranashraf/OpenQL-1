/**
 * @file   eqasm_backend_cc.cc
 * @date   201809xx
 * @author Wouter Vlothuizen (wouter.vlothuizen@tno.nl)
 * @brief  eqasm backend for the Central Controller
 * @remark based on cc_light_eqasm_compiler.h, commit f34c0d9
 */

/*
    Change log:
    20200116:
    - changed JSON field "signal_ref" to "ref_signal" to improve consistency
    - idem "ref_signals_type" to "signal_type"

    Todo:
    - finish support for classical instructions
    - finish support for kernel conditionality
    - allow runtime selection of scheduler
    - port https://github.com/QE-Lab/OpenQL/pull/238 to CC
*/


// options:
#define OPT_CC_SCHEDULE_RC          0       // 1=use resource constraint scheduler

#include "eqasm_backend_cc.h"

#include <options.h>
#include <platform.h>
#include <ir.h>

#include <scheduler.h>

// define classical QASM instructions as generated by classical.h
// FIXME: should be moved to a more sensible location
#define QASM_CLASSICAL_INSTRUCTION_LIST   \
    X(QASM_ADD, "add") \
    X(QASM_SUB, "sub") \
    X(QASM_AND, "and") \
    X(QASM_OR, "or")   \
    X(QASM_XOR, "xor") \
    X(QASM_NOT, "not") \
    X(QASM_NOP, "nop") \
    X(QASM_LDI, "ldi") \
    X(QASM_MOV, "mov") \
    X(QASM_EQ, "eq")   \
    X(QASM_NE, "ne")   \
    X(QASM_LT, "lt")   \
    X(QASM_GT, "gt")   \
    X(QASM_LE, "le")   \
    X(QASM_GE, "ge")

// generate constants for instructions
#define X(_enum, _string) static const char *_enum = _string;
QASM_CLASSICAL_INSTRUCTION_LIST
#undef X


namespace ql {

// compile for Central Controller
// NB: a new eqasm_backend_cc is instantiated per call to compile, so we don't need to cleanup
void eqasm_backend_cc::compile(quantum_program *program, const quantum_platform &platform)
{
    DOUT("Compiling " << program->kernels.size() << " kernels to generate Central Controller program ... ");

    // init
    loadHwSettings(platform);
    codegen.init(platform);
    bundleIdx = 0;

    // generate program header
    codegen.programStart(program->unique_name);

#if OPT_CC_SCHEDULE_RC
    // schedule with platform resource constraints
    rcschedule(program, platform, "rcscheduler");
#else
    // schedule without resource constraints
    schedule(program, platform, "scheduler");
#endif

    // generate code for all kernels
    for(auto &kernel : program->kernels) {
        IOUT("Compiling kernel: " << kernel.name);
        codegenKernelPrologue(kernel);

        circuit &circuit = kernel.c;
        if (!circuit.empty()) {
            ir::bundles_t bundles = ir::bundler(circuit, platform.cycle_time);
            codegen.kernelStart();
            codegenBundles(bundles, platform);
            codegen.kernelFinish(kernel.name, bundles.back().start_cycle+bundles.back().duration_in_cycles);
        } else {
            DOUT("Empty kernel: " << kernel.name);                      // NB: normal situation for kernels with classical control
        }

        codegenKernelEpilogue(kernel);
    }

    codegen.programFinish(program->unique_name);

    // write program to file
    std::string file_name(options::get("output_dir") + "/" + program->unique_name + ".vq1asm");
    IOUT("Writing Central Controller program to " << file_name);
    utils::write_file(file_name, codegen.getProgram());

    // write instrument map to file (unless we were using input file)
    std::string map_input_file = options::get("backend_cc_map_input_file");
    if(map_input_file != "") {
        std::string file_name_map(options::get("output_dir") + "/" + program->unique_name + ".map");
        IOUT("Writing instrument map to " << file_name_map);
        utils::write_file(file_name_map, codegen.getMap());
    }

    DOUT("Compiling Central Controller program [Done]");
}


// based on cc_light_eqasm_compiler.h::classical_instruction2qisa/decompose_instructions
// NB: input instructions defined in classical.h::classical
void eqasm_backend_cc::codegenClassicalInstruction(gate *classical_ins)
{
    auto &iname =  classical_ins->name;
    auto &iopers = classical_ins->creg_operands;
    int iopers_count = iopers.size();

    if(  iname == QASM_ADD || iname == QASM_SUB ||
         iname == QASM_AND || iname == QASM_OR  || iname == QASM_NOT || iname == QASM_XOR ||
         iname == QASM_LDI || iname == QASM_MOV ||
         iname == QASM_NOP
      )
    {
        FATAL("Classical instruction not implemented: " << iname);
    }
    else if( iname == QASM_EQ || iname == QASM_NE || iname == QASM_LT ||
             iname == QASM_GT || iname == QASM_LE || iname == QASM_GE
           )
    {
        FATAL("Classical instruction not implemented: " << iname);
    }
    else
    {
        FATAL("Unknown classical operation'" << iname << "' with'" << iopers_count << "' operands!");
    }
}


// get label from kernel name: FIXME: the label is the program name
// FIXME: the kernel name has a structure (e.g. "sp1_for1_start" or "sp1_for1_start") which we use here. This should be made explicit
// FIXME: looks very inefficient
// extracted from get_epilogue
// FIXME: does not use class
std::string eqasm_backend_cc::kernelLabel(quantum_kernel &k)
{
    std::string kname(k.name);
    std::replace(kname.begin(), kname.end(), '_', ' ');
    std::istringstream iss(kname);
    std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>{} };
    return tokens[0];
}

// handle kernel conditionality at beginning of kernel
// based on cc_light_eqasm_compiler.h::get_prologue
void eqasm_backend_cc::codegenKernelPrologue(quantum_kernel &k)
{
    codegen.comment(SS2S("### Kernel: '" << k.name << "'"));

    switch(k.type) {
        case kernel_type_t::IF_START:
        {
            auto op0 = k.br_condition.operands[0]->id;
            auto op1 = k.br_condition.operands[1]->id;
            auto opName = k.br_condition.operation_name;
            codegen.ifStart(op0, opName, op1);
            break;
        }

        case kernel_type_t::ELSE_START:
        {
            auto op0 = k.br_condition.operands[0]->id;
            auto op1 = k.br_condition.operands[1]->id;
            auto opName = k.br_condition.operation_name;
            codegen.elseStart(op0, opName, op1);
            break;
        }

        case kernel_type_t::FOR_START:
        {
            std::string label = kernelLabel(k);
            codegen.forStart(label, k.iterations);
            break;
        }

        case kernel_type_t::DO_WHILE_START:
        {
            std::string label = kernelLabel(k);
            codegen.doWhileStart(label);
            break;
        }

        case kernel_type_t::STATIC:
        case kernel_type_t::FOR_END:
        case kernel_type_t::DO_WHILE_END:
        case kernel_type_t::IF_END:
        case kernel_type_t::ELSE_END:
            // do nothing
            break;

        default:
            FATAL("inconsistency detected: unhandled kernel type");
            break;
    }
}


// handle kernel conditionality at end of kernel
// based on cc_light_eqasm_compiler.h::get_epilogue
void eqasm_backend_cc::codegenKernelEpilogue(quantum_kernel &k)
{
    switch(k.type) {
        case kernel_type_t::FOR_END:
        {
            std::string label = kernelLabel(k);
            codegen.forEnd(label);
            break;
        }

        case kernel_type_t::DO_WHILE_END:
        {
            auto op0 = k.br_condition.operands[0]->id;
            auto op1 = k.br_condition.operands[1]->id;
            auto opName = k.br_condition.operation_name;
            std::string label = kernelLabel(k);
            codegen.doWhileEnd(label, op0, opName, op1);
            break;
        }

        case kernel_type_t::IF_END:
        case kernel_type_t::ELSE_END:
            // do nothing
            break;

        case kernel_type_t::STATIC:
        case kernel_type_t::IF_START:
        case kernel_type_t::ELSE_START:
        case kernel_type_t::FOR_START:
        case kernel_type_t::DO_WHILE_START:
            // do nothing
            break;

        default:
            FATAL("inconsistency detected: unhandled kernel type");
            break;
    }
}


// based on cc_light_eqasm_compiler.h::bundles2qisa()
void eqasm_backend_cc::codegenBundles(ir::bundles_t &bundles, const quantum_platform &platform)
{
    IOUT("Generating .vq1asm for bundles");

    for(ir::bundle_t &bundle : bundles) {
        // generate bundle header
        DOUT(SS2S("Bundle " << bundleIdx << ": start_cycle=" << bundle.start_cycle << ", duration_in_cycles=" << bundle.duration_in_cycles));
        codegen.bundleStart(SS2S("## Bundle " << bundleIdx++
                                  << ": start_cycle=" << bundle.start_cycle
                                  << ", duration_in_cycles=" << bundle.duration_in_cycles << ":"
                                  ));
        // NB: the "wait" instruction never makes it into the bundle. It is accounted for in scheduling though,
        // and if a non-zero duration is specified that duration is reflected in 'start_cycle' of the subsequent instruction

        // generate code for this bundle
        for(auto section = bundle.parallel_sections.begin(); section != bundle.parallel_sections.end(); ++section ) {
            // check whether section defines classical gate
            gate *firstInstr = *section->begin();
            auto firstInstrType = firstInstr->type();
            if(firstInstrType == __classical_gate__) {
                DOUT(SS2S("Classical bundle: instr='" << firstInstr->name << "'"));
                if(section->size() != 1) {
                    FATAL("Inconsistency detected in bundle contents: classical gate with parallel sections");
                }
                codegenClassicalInstruction(firstInstr);
            } else {
                /* iterate over all instructions in section.
                 * NB: our strategy differs from cc_light_eqasm_compiler, we have no special treatment of first instruction
                 * and don't require all instructions to be identical
                 */
                for(auto insIt = section->begin(); insIt != section->end(); ++insIt) {
                    gate *instr = *insIt;
                    gate_type_t itype = instr->type();
                    std::string iname = instr->name;
                    DOUT(SS2S("Bundle section: instr='" << iname << "'"));

                    switch(itype) {
                        case __nop_gate__:       // a quantum "nop", see gate.h
                            codegen.nopGate();
                            break;

                        case __classical_gate__:
                            FATAL("Inconsistency detected in bundle contents: classical gate found after first section (which itself was non-classical)");
                            break;

                        case __custom_gate__:
                            DOUT(SS2S("Custom gate: instr='" << iname << "'" << ", duration=" << instr->duration) << " ns");
                            codegen.customGate(iname, instr->operands, instr->creg_operands,
                                               instr->angle, bundle.start_cycle, platform.time_to_cycles(instr->duration));
                            break;

                        case __display__:
                            FATAL("Gate type __display__ not supported");           // QX specific, according to openql.pdf
                            break;

                        case __measure_gate__:
                            FATAL("Gate type __measure_gate__ not supported");      // no use, because there is no way to define CC-specifics
                            break;

                        default:
                            FATAL("Unsupported gate type: " << itype);
                    }   // switch(itype)
                } // for(section...)
            }
        }

        // generate bundle trailer, and code for classical gates
        bool isLastBundle = &bundle==&bundles.back();
        codegen.bundleFinish(bundle.start_cycle, bundle.duration_in_cycles, isLastBundle);
    }   // for(bundles)

    IOUT("Generating .vq1asm for bundles [Done]");
}


// based on: cc_light_eqasm_compiler.h::loadHwSettings
void eqasm_backend_cc::loadHwSettings(const quantum_platform &platform)
{
#if 0   // FIXME: currently unused, may be of future use
    const struct {
        size_t  *var;
        std::string name;
    } hw_settings[] = {
#if 0   // FIXME: Convert to cycle. // NB: Visual Studio does not like empty array
        { &mw_mw_buffer,            "mw_mw_buffer" },
        { &mw_flux_buffer,          "mw_flux_buffer" },
        { &mw_readout_buffer,       "mw_readout_buffer" },
        { &flux_mw_buffer,          "flux_mw_buffer" },
        { &flux_flux_buffer,        "flux_flux_buffer" },
        { &flux_readout_buffer,     "flux_readout_buffer" },
        { &readout_mw_buffer,       "readout_mw_buffer" },
        { &readout_flux_buffer,     "readout_flux_buffer" },
        { &readout_readout_buffer,  "readout_readout_buffer" }
#endif
    };

    DOUT("Loading hardware settings ...");
    size_t i=0;
    try
    {
        for(i=0; i<ELEM_CNT(hw_settings); i++) {
            size_t val = platform.hardware_settings[hw_settings[i].name];
            *hw_settings[i].var = val;
        }
    }
    catch (json::exception &e)
    {
        throw exception(
            "[x] error : eqasm_compiler::compile() : error while reading hardware settings : parameter '"
            + hw_settings[i].name
            + "'\n\t"
            + std::string(e.what()), false);
    }
#endif
}

} // namespace ql

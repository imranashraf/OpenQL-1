#include "gate.h"

#include <cctype>

namespace ql {

identity::identity(size_t q) : m(identity_c) {
    name = "i";
    duration = 40;
    operands.push_back(q);
}

instruction_t identity::qasm() const {
    return instruction_t("i q[" + std::to_string(operands[0]) + "]");
}

gate_type_t identity::type() const {
    return __identity_gate__;
}

cmat_t identity::mat() const {
    return m;
}

hadamard::hadamard(size_t q) : m(hadamard_c) {
    name = "h";
    duration = 40;
    operands.push_back(q);
}

instruction_t hadamard::qasm() const {
    return instruction_t("h q[" + std::to_string(operands[0]) + "]");
}

gate_type_t hadamard::type() const {
    return __hadamard_gate__;
}

cmat_t hadamard::mat() const {
    return m;
}

phase::phase(size_t q) : m(phase_c) {
    name = "s";
    duration = 40;
    operands.push_back(q);
}

instruction_t phase::qasm() const {
    return instruction_t("s q[" + std::to_string(operands[0]) + "]");
}

gate_type_t phase::type() const {
    return __phase_gate__;
}

cmat_t phase::mat() const {
    return m;
}

/**
 * phase dag
 */
phasedag::phasedag(size_t q) : m(phasedag_c) {
    name = "sdag";
    duration = 40;
    operands.push_back(q);
}

instruction_t phasedag::qasm() const {
    return instruction_t("sdag q[" + std::to_string(operands[0]) + "]");
}

gate_type_t phasedag::type() const {
    return __phasedag_gate__;
}

cmat_t phasedag::mat() const {
    return m;
}

rx::rx(size_t q, double theta) {
    name = "rx";
    duration = 40;
    angle = theta;
    operands.push_back(q);
    m(0,0) = cos(angle/2);
    m(0,1) = complex_t(0,-sin(angle/2));
    m(1,0) = complex_t(0,-sin(angle/2));
    m(1,1) = cos(angle/2);
}

instruction_t rx::qasm() const {
    return instruction_t("rx q[" + std::to_string(operands[0]) + "], " + std::to_string(angle) );
}

gate_type_t rx::type() const {
    return __rx_gate__;
}

cmat_t rx::mat() const {
    return m;
}

ry::ry(size_t q, double theta) {
    name = "ry";
    duration = 40;
    angle = theta;
    operands.push_back(q);
    m(0,0) = cos(angle/2);
    m(0,1) = -sin(angle/2);
    m(1,0) = sin(angle/2);
    m(1,1) = cos(angle/2);
}

instruction_t ry::qasm() const {
    return instruction_t("ry q[" + std::to_string(operands[0]) + "], " + std::to_string(angle) );
}

gate_type_t ry::type() const {
    return __ry_gate__;
}

cmat_t ry::mat() const {
    return m;
}

rz::rz(size_t q, double theta) {
    name = "rz";
    duration = 40;
    angle = theta;
    operands.push_back(q);
    m(0,0) = complex_t(cos(-angle/2), sin(-angle/2));
    m(0,1) = 0;
    m(1,0) = 0;
    m(1,1) =  complex_t(cos(angle/2), sin(angle/2));
}

instruction_t rz::qasm() const {
    return instruction_t("rz q[" + std::to_string(operands[0]) + "], " + std::to_string(angle) );
}

gate_type_t rz::type() const {
    return __rz_gate__;
}

cmat_t rz::mat() const {
    return m;
}

t::t(size_t q) : m(t_c) {
    name = "t";
    duration = 40;
    operands.push_back(q);
}

instruction_t t::qasm() const {
    return instruction_t("t q[" + std::to_string(operands[0]) + "]");
}

gate_type_t t::type() const {
    return __t_gate__;
}

cmat_t t::mat() const {
    return m;
}

tdag::tdag(size_t q) : m(tdag_c) {
    name = "tdag";
    duration = 40;
    operands.push_back(q);
}

instruction_t tdag::qasm() const {
    return instruction_t("tdag q[" + std::to_string(operands[0]) + "]");
}

gate_type_t tdag::type() const {
    return __tdag_gate__;
}

cmat_t tdag::mat() const {
    return m;
}

pauli_x::pauli_x(size_t q) : m(pauli_x_c) {
    name = "x";
    duration = 40;
    operands.push_back(q);
}

instruction_t pauli_x::qasm() const {
    return instruction_t("x q[" + std::to_string(operands[0]) + "]");
}

gate_type_t pauli_x::type() const {
    return __pauli_x_gate__;
}

cmat_t pauli_x::mat() const {
    return m;
}

pauli_y::pauli_y(size_t q) : m(pauli_y_c) {
    name = "y";
    duration = 40;
    operands.push_back(q);
}

instruction_t pauli_y::qasm() const {
    return instruction_t("y q[" + std::to_string(operands[0]) + "]");
}

gate_type_t pauli_y::type() const {
    return __pauli_y_gate__;
}

cmat_t pauli_y::mat() const {
    return m;
}

pauli_z::pauli_z(size_t q) : m(pauli_z_c) {
    name = "z";
    duration = 40;
    operands.push_back(q);
}

instruction_t pauli_z::qasm() const {
    return instruction_t("z q[" + std::to_string(operands[0]) + "]");
}

gate_type_t pauli_z::type() const {
    return __pauli_z_gate__;
}

cmat_t pauli_z::mat() const {
    return m;
}

rx90::rx90(size_t q) : m(rx90_c) {
    name = "x90";
    duration = 40;
    operands.push_back(q);
}

instruction_t rx90::qasm() const {
    return instruction_t("x90 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t rx90::type() const {
    return __rx90_gate__;
}

cmat_t rx90::mat() const {
    return m;
}

mrx90::mrx90(size_t q) : m(mrx90_c) {
    name = "mx90";
    duration = 40;
    operands.push_back(q);
}

instruction_t mrx90::qasm() const {
    return instruction_t("mx90 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t mrx90::type() const {
    return __mrx90_gate__;
}

cmat_t mrx90::mat() const {
    return m;
}

rx180::rx180(size_t q) : m(rx180_c) {
    name = "x180";
    duration = 40;
    operands.push_back(q);
}

instruction_t rx180::qasm() const {
    return instruction_t("x180 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t rx180::type() const {
    return __rx180_gate__;
}

cmat_t rx180::mat() const {
    return m;
}

ry90::ry90(size_t q) : m(ry90_c) {
    name = "y90";
    duration = 40;
    operands.push_back(q);
}

instruction_t ry90::qasm() const {
    return instruction_t("y90 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t ry90::type() const {
    return __ry90_gate__;
}

cmat_t ry90::mat() const {
    return m;
}

mry90::mry90(size_t q) : m(mry90_c) {
    name = "my90";
    duration = 40;
    operands.push_back(q);
}

instruction_t mry90::qasm() const {
    return instruction_t("my90 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t mry90::type() const {
    return __mry90_gate__;
}

cmat_t mry90::mat() const {
    return m;
}

ry180::ry180(size_t q) : m(ry180_c) {
    name = "y180";
    duration = 40;
    operands.push_back(q);
}

instruction_t ry180::qasm() const {
    return instruction_t("y180 q[" + std::to_string(operands[0]) + "]");
}

gate_type_t ry180::type() const {
    return __ry180_gate__;
}

cmat_t ry180::mat() const {
    return m;
}

measure::measure(size_t q) : m(identity_c) {
    name = "measure";
    duration = 40;
    operands.push_back(q);
}

measure::measure(size_t q, size_t c) : m(identity_c) {
    name = "measure";
    duration = 40;
    operands.push_back(q);
    creg_operands.push_back(c);
}

instruction_t measure::qasm() const {
    std::stringstream ss;
    ss << "measure ";
    ss << "q[" << operands[0] << "]";
    if (!creg_operands.empty()) {
        ss << ", r[" << creg_operands[0] << "]";
    }

    return instruction_t(ss.str());
}

gate_type_t measure::type() const {
    return __measure_gate__;
}

cmat_t measure::mat() const {
    return m;
}

prepz::prepz(size_t q) : m(identity_c) {
    name = "prep_z";
    duration = 40;
    operands.push_back(q);
}

instruction_t prepz::qasm() const {
    return instruction_t("prep_z q[" + std::to_string(operands[0]) +"]");
}

gate_type_t prepz::type() const {
    return __prepz_gate__;
}

cmat_t prepz::mat() const {
    return m;
}

cnot::cnot(size_t q1, size_t q2) : m(cnot_c) {
    name = "cnot";
    duration = 80;
    operands.push_back(q1);
    operands.push_back(q2);
}

instruction_t cnot::qasm() const {
    return instruction_t("cnot q[" + std::to_string(operands[0]) + "]"
                         + ",q[" + std::to_string(operands[1]) + "]");
}

gate_type_t cnot::type() const {
    return __cnot_gate__;
}

cmat_t cnot::mat() const {
    return m;
}

cphase::cphase(size_t q1, size_t q2) : m(cphase_c) {
    name = "cz";
    duration = 80;
    operands.push_back(q1);
    operands.push_back(q2);
}

instruction_t cphase::qasm() const {
    return instruction_t("cz q[" + std::to_string(operands[0]) + "]"
                         + ",q[" + std::to_string(operands[1]) + "]");
}

gate_type_t cphase::type() const {
    return __cphase_gate__;
}

cmat_t cphase::mat() const {
    return m;
}

toffoli::toffoli(size_t q1, size_t q2, size_t q3) : m(ctoffoli_c) {
    name = "toffoli";
    duration = 160;
    operands.push_back(q1);
    operands.push_back(q2);
    operands.push_back(q3);
}

instruction_t toffoli::qasm() const {
    return instruction_t("toffoli q[" + std::to_string(operands[0]) + "]"
                         + ",q[" + std::to_string(operands[1]) + "]"
                         + ",q[" + std::to_string(operands[2]) + "]");
}

gate_type_t toffoli::type() const {
    return __toffoli_gate__;
}

cmat_t toffoli::mat() const {
    return m;
}

nop::nop() : m(nop_c) {
    name = "wait";
    duration = 20;
}

instruction_t nop::qasm() const {
    return instruction_t("nop");
}

gate_type_t nop::type() const {
    return __nop_gate__;
}

cmat_t nop::mat() const {
    return m;
}

swap::swap(size_t q1, size_t q2) : m(swap_c) {
    name = "swap";
    duration = 80;
    operands.push_back(q1);
    operands.push_back(q2);
}

instruction_t swap::qasm() const {
    return instruction_t("swap q[" + std::to_string(operands[0]) + "]"
                         + ",q[" + std::to_string(operands[1]) + "]");
}

gate_type_t swap::type() const {
    return __swap_gate__;
}

cmat_t swap::mat() const {
    return m;
}

/****************************************************************************\
| Special gates
\****************************************************************************/

wait::wait(std::vector<size_t> qubits, size_t d, size_t dc) : m(nop_c) {
    name = "wait";
    duration = d;
    duration_in_cycles = dc;
    for (auto &q : qubits) {
        operands.push_back(q);
    }
}

instruction_t wait::qasm() const {
    return instruction_t("wait " + std::to_string(duration_in_cycles));
}

gate_type_t wait::type() const {
    return __wait_gate__;
}

cmat_t wait::mat() const {
    return m;
}

SOURCE::SOURCE() : m(nop_c) {
    name = "SOURCE";
    duration = 1;
}

instruction_t SOURCE::qasm() const {
    return instruction_t("SOURCE");
}

gate_type_t SOURCE::type() const {
    return __dummy_gate__;
}

cmat_t SOURCE::mat() const {
    return m;
}

SINK::SINK() : m(nop_c) {
    name = "SINK";
    duration = 1;
}

instruction_t SINK::qasm() const {
    return instruction_t("SINK");
}

gate_type_t SINK::type() const {
    return __dummy_gate__;
}

cmat_t SINK::mat() const {
    return m;
}

display::display() : m(nop_c) {
    name = "display";
    duration = 0;
}

instruction_t display::qasm() const {
    return instruction_t("display");
}

gate_type_t display::type() const {
    return __display__;
}

cmat_t display::mat() const {
    return m;
}

custom_gate::custom_gate(const std::string &name) {
    this->name = name;  // just remember name, e.g. "x", "x %0" or "x q0", expansion is done by add_custom_gate_if_available().
    // FIXME: no syntax check is performed
}

custom_gate::custom_gate(const custom_gate &g) {
    // FIXME JvS: This copy constructor does NOT copy everything, and apparently
    // the scheduler relies on it not doing so!
    DOUT("Custom gate copy constructor for " << g.name);
    name = g.name;
    // operands = g.operands; FIXME
    creg_operands = g.creg_operands;
    // int_operand = g.int_operand; FIXME
    duration = g.duration;
    // angle = g.angle; FIXME
    // cycle = g.cycle; FIXME
    m.m[0] = g.m.m[0];
    m.m[1] = g.m.m[1];
    m.m[2] = g.m.m[2];
    m.m[3] = g.m.m[3];
}

/**
 * match qubit id
 */
bool custom_gate::is_qubit_id(const std::string &str) {
    if (str[0] != 'q') {
        return false;
    }
    size_t l = str.length();
    for (size_t i = 1; i < l; ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/**
 * return qubit id
 */
size_t custom_gate::qubit_id(const std::string &qubit) {
    std::string id = qubit.substr(1);
    return std::atoi(id.c_str());
}

/**
 * load instruction from json map
 */
void custom_gate::load(nlohmann::json &instr) {
    DOUT("loading instruction '" << name << "'...");
    std::string l_attr = "(none)";
    try {
        l_attr = "qubits";
        DOUT("qubits: " << instr["qubits"]);
        size_t parameters = instr["qubits"].size();
        for (size_t i = 0; i < parameters; ++i) {
            std::string qid = instr["qubits"][i];
            if (!is_qubit_id(qid)) {
                EOUT("invalid qubit id in attribute 'qubits' !");
                throw ql::exception(
                    "[x] error : ql::custom_gate() : error while loading instruction '" +
                    name + "' : attribute 'qubits' : invalid qubit id !",
                    false);
            }
            operands.push_back(qubit_id(qid));
        }
        l_attr = "duration";
        duration = instr["duration"];
        DOUT("duration: " << instr["duration"]);
        l_attr = "matrix";
        // FIXME: make matrix optional, default to NaN
        auto mat = instr["matrix"];
        DOUT("matrix: " << instr["matrix"]);
        m.m[0] = complex_t(mat[0][0], mat[0][1]);
        m.m[1] = complex_t(mat[1][0], mat[1][1]);
        m.m[2] = complex_t(mat[2][0], mat[2][1]);
        m.m[3] = complex_t(mat[3][0], mat[3][1]);
    } catch (json::exception &e) {
        EOUT("while loading instruction '" << name << "' (attr: " << l_attr
                                           << ") : " << e.what());
        throw ql::exception(
            "[x] error : ql::custom_gate() : error while loading instruction '" +
            name + "' : attribute '" + l_attr + "' : \n\t" + e.what(), false);
    }

    if (instr.count("cc_light_instr") > 0) {
        arch_operation_name = instr["cc_light_instr"].get<std::string>();
        DOUT("cc_light_instr: " << instr["cc_light_instr"]);
    }
}

void custom_gate::print_info() const {
    println("[-] custom gate : ");
    println("    |- name     : " << name);
    utils::print_vector(operands,"[openql]     |- qubits   :"," , ");
    println("    |- duration : " << duration);
    println("    |- matrix   : [" << m.m[0] << ", " << m.m[1] << ", " << m.m[2] << ", " << m.m[3] << "]");
}

instruction_t custom_gate::qasm() const {
    std::stringstream ss;
    size_t p = name.find(' ');
    std::string gate_name = name.substr(0, p);
    if (operands.empty()) {
        ss << gate_name;
    } else if (operands.size() == 1) {
        ss << gate_name << " q[" << operands[0] << "]";
    } else {
        ss << gate_name << " q[" << operands[0] << "]";
        for (size_t i = 1; i < operands.size(); i++) {
            ss << ",q[" << operands[i] << "]";
        }
    }

    // deal with custom gates with argument, such as angle
    if (gate_name == "rx" || gate_name == "ry" || gate_name == "rz") {
        ss << ", " << angle;
    }

    if (creg_operands.size() == 1) {
        ss << ",r" << creg_operands[0];
    } else if (creg_operands.size() > 1) {
        ss << ",r" << creg_operands[0];
        for (size_t i = 1; i < creg_operands.size(); i++) {
            ss << ",r" << creg_operands[i];
        }
    }

    return instruction_t(ss.str());
}

gate_type_t custom_gate::type() const {
    return __custom_gate__;
}

cmat_t custom_gate::mat() const {
    return m;
}

composite_gate::composite_gate(const std::string &name) : custom_gate(name) {
    duration = 0;
}

composite_gate::composite_gate(const std::string &name, const std::vector<gate*> &seq) : custom_gate(name) {
    duration = 0;
    for (gate *g : seq) {
        gs.push_back(g);
        duration += g->duration;    // FIXME: not true if gates operate in parallel
        operands.insert(operands.end(), g->operands.begin(), g->operands.end());
    }
}

instruction_t composite_gate::qasm() const {
    std::stringstream instr;
    for (gate * g : gs) {
        instr << g->qasm() << std::endl;
    }
    return instruction_t(instr.str());
}

gate_type_t composite_gate::type() const {
    return __composite_gate__;
}

cmat_t composite_gate::mat() const {
    return m;   // FIXME: never initialized
}

} // namespace ql

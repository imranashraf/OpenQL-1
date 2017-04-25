/*
 * Author: Imran Ashraf
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cassert>

#include <time.h>

#include "globals.h"
#include "ql/openql.h"

// create a kernel
ql::quantum_kernel kernel("myKernel");

// create program
ql::quantum_program prog("prog",3);

EXPORT int init()
{
   srand(0);

   float sweep_points[] = {2};
   int   num_circuits   = 1;

   // specify the platform
   ql::init(ql::transmon_platform, "instructions.map");

   prog.set_sweep_points(sweep_points, num_circuits);

   // add gates to kernel
   kernel.prepz(0);
   kernel.prepz(1);
   kernel.x(0);
   kernel.y(0);
   kernel.cnot(0,1);
   kernel.toffoli(0,1,2);
   kernel.measure(2);

   // add kernel to prog
   prog.add(kernel);

   return 0;
}

EXPORT int compile()
{
    // compile the program
    prog.compile(1);
}

EXPORT int schedule()
{
   // schedule program to generate scheduled qasm
   prog.schedule();
   return 0;
}
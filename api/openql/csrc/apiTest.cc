/*
 * Author: Imran Ashraf
 */

#include<iostream>
#include "api/openql/csrc/api.h"

int main(int argc, char ** argv)
{
    std::cout << "OpenQL Python API Test" << std::endl;
    init();
    schedule();
    return 0;
}
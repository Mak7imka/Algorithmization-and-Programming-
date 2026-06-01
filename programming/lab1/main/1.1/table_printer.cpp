#include "table_printer.h"
#include <iostream>
#include <iomanip>

void printFunctionTable(double start, double end, double step, FunctionPtr func) {
    std::cout << std::setw(10) << "Start" << std::setw(10) << "End" 
              << std::setw(10) << "Step" << std::setw(10) << "x" 
              << std::setw(15) << "Result" << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    for (double x = start; x <= end; x += step) {
        std::cout << std::fixed << std::setprecision(4)
                  << std::setw(10) << start
                  << std::setw(10) << end
                  << std::setw(10) << step
                  << "\033[32m" 
                  << std::setw(10) << x
                  << std::setw(15) << func(x)
                  << "\033[0m" 
                  << std::endl;
    }
    std::cout << std::endl; 
}
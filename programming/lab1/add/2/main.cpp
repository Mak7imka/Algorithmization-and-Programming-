#include "calculator.h"
#include <iostream>

int main() {
    std::cout << "calculate() = " << Calculator::calculate() << "\n";
    std::cout << "calculate(5) = " << Calculator::calculate(2) << "\n";
    std::cout << "calculate(2, 3) = " << Calculator::calculate(5, 8) << "\n";
    std::cout << "calculate(2, 3, 4) = " << Calculator::calculate(5, 8, 14) << "\n";

    std::cout << "multiply(2, 3) = " << Calculator::multiply(5, 8) << "\n";
    std::cout << "multiply(2, 3, 4) = " << Calculator::multiply(5, 8, 14) << "\n";
    std::cout << "multiply(5) = " << Calculator::multiply(2) << "\n";

    return 0;
}

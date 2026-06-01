#include "mathfunc.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using MathOperations::MathFunction;

int main() {
  MathFunction functions[] = {
    std::pow,
    std::hypot,
    std::fmax,
    std::fmin,
    sumSquares
  };
  
  const char* functionNames[] = {
    "pow",
    "hypot",
    "fmax",
    "fmin",
    "sumSquares"
  };
  
  double x, y;
  std::cout << "Введіть значення x: ";
  std::cin >> x;
  std::cout << "Введіть значення y: ";
  std::cin >> y;
  
  std::cout << "\nРезультати обчислень:\n";
  std::cout << std::string(50, '-') << std::endl;
  
  // 1. explicit access qualification
  std::cout << "Спосіб 1 - Явна кваліфікація:\n";
  for (int i = 0; i < 5; ++i) {
    std::cout << std::setw(12) << functionNames[i];
    MathOperations::printResult(functions[i], x, y);
  }
  
  std::cout << std::string(67, '-') << std::endl;
  
  // 2. using-directive 
  std::cout << "Спосіб 2 - Using-директива:\n";
  {
    using namespace MathOperations;
    for (int i = 0; i < 5; ++i) {
      std::cout << std::setw(12) << functionNames[i];
      printResult(functions[i], x, y);
    }
  }
  
  std::cout << std::string(67, '-') << std::endl;
  
  // 3. using-declaration 
  std::cout << "Спосіб 3 - Using-оголошення:\n";
  {
    using MathOperations::printResult;
    std::cout << std::setw(12) << "sumSquares";
    printResult(sumSquares, x, y);  
  }
  
  return 0;
}

#include "mathfunc.h"
#include <iostream>
#include <iomanip>

namespace MathOperations {
  void printResult(MathFunction func, double x, double y) {
    std::cout << " | x = " << std::setw(8) << std::fixed << std::setprecision(2) << x 
              << ", y = " << std::setw(8) << y 
              << " | Результат = " << std::setw(10) << func(x, y) << std::endl;
  }
}


double sumSquares(double x, double y) {
  return x * x + y * y;
}

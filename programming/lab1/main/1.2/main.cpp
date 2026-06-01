#include "root_finder.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Test function 1: polynomial function x^3 - 2x^2 - x + 2
// Its second derivative is 6x - 4
// The root of second derivative is at x = 2/3
double testFunction1(double x) {
  return pow(x, 3) - 2 * pow(x, 2) - x + 2;
}

// Test function 2: sin(x) + x^2
// Its second derivative is -sin(x) + 2
double testFunction2(double x) {
  return sin(x) + pow(x, 2);
}

void printResult(const char* functionName, double root) {
  std::cout << "\nНайбільший корінь другої похідної для " << functionName << ": "
            << std::fixed << std::setprecision(6) << root << std::endl;
}

int main() {

  double start = -5.0;
  double end = 5.0;
  double step = 0.01;
  
  double root1 = LargestRoot(testFunction1, start, end, step);
  printResult("x^3 - 2x^2 - x + 2", root1);
  
  double root2 = LargestRoot(testFunction2, start, end, step);
  printResult("sin(x) + x^2", root2);
  
  return 0;
}

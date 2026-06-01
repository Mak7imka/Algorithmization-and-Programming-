#include "root_finder.h"
#include <cmath>

// first derivative (provided formula)
double firstDerivative(FunctionPtr func, double x, double dx = 1e-7) {
  return (func(x + dx) - func(x)) / dx;
}

// second derivative
double secondDerivative(FunctionPtr func, double x, double dx = 1e-7) {
  return (firstDerivative(func, x + dx) - firstDerivative(func, x)) / dx;
}

double LargestRoot(FunctionPtr func, double start, double end, double step, double epsilon) {
  double largestRoot = start;
  bool foundRoot = false;
  
  // Iterate through the interval
  for (double x = start; x <= end; x += step) {
      double y2 = secondDerivative(func, x);
      double y2_next = secondDerivative(func, x + step);
      
      // Check if second derivative changes sign (crosses zero)
      if (std::abs(y2) < epsilon || (y2 * y2_next <= 0)) {
          if (!foundRoot || x > largestRoot) {
              largestRoot = x;
              foundRoot = true;
          }
      }
  }
  
  return foundRoot ? largestRoot : start;
}

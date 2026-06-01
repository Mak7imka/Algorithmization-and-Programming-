#include "equation_solver.h"
#include <cmath>

int solveQuadraticEquation(double a, double b, double c, double& root1, double& root2) {
  double discriminant = [=]() -> double {
    return b * b - 4 * a * c;
  }();

  if (a == 0 && b == 0 && c == 0) {
    return -1;
  }
  else if (a == 0 && b == 0) {
    return 0;
  }
  else if (a == 0) {
    root1 = -c / b;
    return 1;
  }

  if (discriminant < 0) {
    return 0;
  }
  else if (discriminant == 0) {
    root1 = -b / (2 * a);
    return 1;
  }
  else {
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    return 2;
  }
}

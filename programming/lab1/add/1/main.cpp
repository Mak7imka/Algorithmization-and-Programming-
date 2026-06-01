#include "equation_solver.h"
#include <iostream>

int main() {
  double a, b, c;
  double root1 = 0, root2 = 0;

  std::cout << "Введіть коефіцієнти a, b, c: ";
  std::cin >> a >> b >> c;

  int numRoots = solveQuadraticEquation(a, b, c, root1, root2);

  switch (numRoots) {
    case -1:
      std::cout << "Рівняння має безліч розв'язків." << std::endl;
      break;
    case 0:
      std::cout << "Рівняння не має дійсних коренів." << std::endl;
      break;
    case 1:
      std::cout << "Рівняння має один корінь: " << root1 << std::endl;
      break;
    case 2:
      std::cout << "Рівняння має два корені: " << root1 << " і " << root2 << std::endl;
      break;
  }

  return 0;
}

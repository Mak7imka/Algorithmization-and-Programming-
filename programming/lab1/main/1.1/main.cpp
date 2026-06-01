#include "table_printer.h"
#include <iostream>
#include <cmath>

// First test function (given)
double function1(double x) {
    double result = 0.0;
    int n = 2;
    if (x <= 0) {
        result = x;
        for (int i = 0; i < n; ++i) {
            result *= (pow(i, 3) + x);
        }
    } else {
        result = 0.0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result += x / (i + j); 
            }
        }
    }
    return result;
}

// // Second test function 
double function2(double x) {
  if (x < 0) {
      return NAN; 
  }
  if (x == 0) {
      return 1; 
  }
  double result = 1;
  for (int i = 1; i <= x; ++i) {
      result *= i;
  }
  return result;
}


void readData(double& a, double& b, double& h) {
    std::cout << "Введіть початок інтервалу a: ";
    std::cin >> a;

    std::cout << "Введіть кінець інтервалу b: ";
    std::cin >> b;

    do {
      std::cout << "Введіть крок h (h > 0): ";
      std::cin >> h;
      if (h <= 0) {
          std::cout << "Крок h повинен бути більше 0. Спробуйте ще раз.\n";
      }
  } while (h <= 0);
}


int main() {
    double a, b, h;

    readData(a, b, h);

    std::cout << "Testing Function 1 (given function):" << std::endl;
    printFunctionTable(a, b, h, function1);

    std::cout << "\nTesting Function 2 (count factorial):" << std::endl;
    printFunctionTable(a, b, h, function2);

    return 0;
}

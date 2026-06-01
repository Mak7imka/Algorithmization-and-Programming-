#include <iostream>
#include <iomanip>
#include "polynomial_finder.h"

int main() {
    PolynomialFinder finder;

    double start;
    std::cout << "Введіть початок інтервалу: ";
    std::cin >> start;

    double end;
    std::cout << "Введіть кінець інтервалу: ";
    std::cin >> end;

    double step;
    std::cout << "Введіть крок: ";
    std::cin >> step;

    double first = finder.firstDerivative(start);
    double second = finder.secondDerivative(start);
    std::cout << "Перша похідна в точці " << start << ": " << first << std::endl;
    std::cout << "Друга похідна в точці " << start << ": " << second << std::endl;

    double root = finder.findLargestRoot(start, end, step);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Найбільший корінь другої похідної: " << root << std::endl;

    return 0;
}

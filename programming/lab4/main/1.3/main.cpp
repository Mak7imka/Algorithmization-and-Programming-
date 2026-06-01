#include "root_finder_template.h"
#include <iostream>
#include <iomanip>
#include <cmath>

//func x^3 - 2x^2 - x + 2
double polyFunc(double x) {
    return std::pow(x, 3) - 2 * std::pow(x, 2) - x + 2;
}

//func sin(x) + x^2
struct SinQuadratic {
    double operator()(double x) const {
        return std::sin(x) + x * x;
    }
};

int main() {
    double start = -5.0;
    double end = 5.0;
    double step = 0.01;

    double root1 = LargestRoot(polyFunc, start, end, step);
    std::cout << "Найбільший корінь другої похідної для polyFunc: "
              << std::fixed << std::setprecision(6) << root1 << std::endl;

    SinQuadratic sinQuad;
    double root2 = LargestRoot(sinQuad, start, end, step);
    std::cout << "Найбільший корінь другої похідної для SinQuadratic: "
              << std::fixed << std::setprecision(6) << root2 << std::endl;

    return 0;
}

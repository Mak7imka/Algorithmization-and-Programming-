#ifndef POLYNOMIAL_FINDER_H
#define POLYNOMIAL_FINDER_H

#include "root_finder_base.h"

class PolynomialFinder : public RootFinder {
public:
    // Реалізація конкретної функції: x^3 - 2x^2 - x + 2
    double function(double x) const override {
        return pow(x, 3) - 2 * pow(x, 2) - x + 2;
    }
};

#endif 
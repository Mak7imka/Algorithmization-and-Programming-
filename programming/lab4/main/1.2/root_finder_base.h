#ifndef ROOT_FINDER_BASE_H
#define ROOT_FINDER_BASE_H

#include <cmath>
#include <cstdlib>

class RootFinder {
public:
    virtual ~RootFinder() {}

    virtual double function(double x) const = 0;

    double firstDerivative(double x, double dx = 1e-7) const {
        return (function(x + dx) - function(x)) / dx;
    }

    double secondDerivative(double x, double dx = 1e-7) const {
        return (firstDerivative(x + dx) - firstDerivative(x)) / dx;
    }

    double findLargestRoot(double start, double end, double step, double epsilon = 1e-7) const {
        double largestRoot = start;
        bool foundRoot = false;

        for (double x = start; x <= end; x += step) {
            double y2 = secondDerivative(x);
            double y2_next = secondDerivative(x + step);

            if (std::abs(y2) < epsilon || (y2 * y2_next <= 0)) {
                if (!foundRoot || x > largestRoot) {
                    largestRoot = x;
                    foundRoot = true;
                }
            }
        }

        return foundRoot ? largestRoot : start;
    }
};

#endif 
#ifndef ROOT_FINDER_TEMPLATE_H
#define ROOT_FINDER_TEMPLATE_H

#include <cmath>
#include <functional>

template <typename Func>
double firstDerivative(Func f, double x, double dx = 1e-7) {
    return (f(x + dx) - f(x)) / dx;
}

template <typename Func>
double secondDerivative(Func f, double x, double dx = 1e-7) {
    return (firstDerivative(f, x + dx, dx) - firstDerivative(f, x, dx)) / dx;
}

template <typename Func>
double LargestRoot(Func f, double start, double end, double step, double epsilon = 1e-7) {
    double largestRoot = start;
    bool foundRoot = false;

    for (double x = start; x <= end; x += step) {
        double y2 = secondDerivative(f, x);
        double y2_next = secondDerivative(f, x + step);

        if (std::abs(y2) < epsilon || (y2 * y2_next <= 0)) {
            if (!foundRoot || x > largestRoot) {
                largestRoot = x;
                foundRoot = true;
            }
        }
    }

    return foundRoot ? largestRoot : start;
}

#endif
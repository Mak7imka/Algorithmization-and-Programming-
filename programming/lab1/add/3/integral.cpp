#include "integral.h"
#include <cmath>

// Метод прямокутників
double rectangleMethod(MathFunction f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    
    return h * sum;
}

// Метод трапецій
double trapezoidMethod(MathFunction f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

double linear(double x) {
    return x;  // f(x) = x
}

double quadratic(double x) {
    return x * x;  // f(x) = x^2
}

double cubic(double x) {
    return x * x * x;  // f(x) = x^3
}

double sinFunction(double x) {
    return sin(x);  // f(x) = sin(x)
}

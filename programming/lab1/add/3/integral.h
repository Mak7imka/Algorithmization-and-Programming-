#ifndef INTEGRAL_H
#define INTEGRAL_H

typedef double (*MathFunction)(double);

typedef double (*IntegrationMethod)(MathFunction f, double a, double b, int n);

double rectangleMethod(MathFunction f, double a, double b, int n);
double trapezoidMethod(MathFunction f, double a, double b, int n);

double linear(double x);
double quadratic(double x);
double cubic(double x);
double sinFunction(double x);

#endif

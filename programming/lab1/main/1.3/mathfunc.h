#ifndef MATHFUNC_H
#define MATHFUNC_H

namespace MathOperations {
    typedef double (*MathFunction)(double, double);
    
    void printResult(MathFunction func, double x, double y);
}

double sumSquares(double x, double y);

#endif 

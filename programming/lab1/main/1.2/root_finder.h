#ifndef ROOT_FINDER_H
#define ROOT_FINDER_H

// pointer type for functions
typedef double (*FunctionPtr)(double);

double LargestRoot(FunctionPtr func, double start, double end, double step, double epsilon = 1e-7);

#endif 

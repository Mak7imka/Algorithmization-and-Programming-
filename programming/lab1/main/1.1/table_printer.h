#ifndef TABLE_PRINTER_H
#define TABLE_PRINTER_H

typedef double (*FunctionPtr)(double); 

void printFunctionTable(double start, double end, double step, FunctionPtr func); 

#endif

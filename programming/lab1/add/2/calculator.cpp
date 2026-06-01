#include "calculator.h"

namespace Calculator {
    int calculate(int a, int b, int c) {
        if (a == 1 && b == 1 && c == 1) {
            return 1; // 0
        } else if (b == 1 && c == 1) {
            return a; // 1
        } else if (c == 1) {
            return a * b; // 2
        } else {
            return a * b * c; // 3
        }
    }

    int multiply(int a, int b) {
        return a * b;
    }

    int multiply(int a, int b, int c) {
        return a * b * c;
    }

    int multiply(int a) {
        return a;
    }
}

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <numeric>

class Fraction {
    int numerator, denominator;

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0)
            throw std::invalid_argument("Denominator cannot be zero");

        int g = std::gcd(num, denom);
        numerator = num / g;
        denominator = denom / g;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.numerator << "/" << f.denominator;
    }
};

#endif 
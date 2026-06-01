#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <numeric> 

class Fraction {
    int numerator, denominator;

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int denom) {
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

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.numerator << "/" << f.denominator;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero during input");
        }
        int g = std::gcd(f.numerator, f.denominator);
        f.numerator /= g;
        f.denominator /= g;
        if (f.denominator < 0) {
            f.numerator *= -1;
            f.denominator *= -1;
        }
        return is;
    }
};

#endif 
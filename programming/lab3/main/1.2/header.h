#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdexcept>
#include <cmath>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Fraction(int num = 0, int denom = 1);
    
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int denom);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);
};

#endif

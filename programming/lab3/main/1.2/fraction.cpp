#include "header.h"

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    simplify();
}

int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::simplify() {
    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
    
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

// Гетери/сетери
int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int num) { 
    numerator = num; 
    simplify();
}

void Fraction::setDenominator(int denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    denominator = denom;
    simplify();
}

// Арифметичні оператори
Fraction Fraction::operator+(const Fraction& other) const {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDenom = denominator * other.denominator;
    return Fraction(newNum, newDenom);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNum = numerator * other.denominator - other.numerator * denominator;
    int newDenom = denominator * other.denominator;
    return Fraction(newNum, newDenom);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

// Оператори порівняння
bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& other) const {
    return (*this < other) || (*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

// Оператори введення/виведення
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    if (frac.denominator == 1 || frac.numerator == 0) {
        os << frac.numerator; 
    } else {
        os << frac.numerator << "/" << frac.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& frac) {
    int num, denom = 1;
    char slash;
    
    is >> num; 
    
    if (is.peek() == '/') { 
        is >> slash >> denom;
    }
    
    frac = Fraction(num, denom);
    return is;
}

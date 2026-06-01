#include "header.h"

int main() {
    try {
        // Створення дробів
        Fraction a;
        Fraction b;

        std::cout << "Enter fraction a (format 'a/b' or 'a'): ";
        std::cin >> a;     
        std::cout << "Enter fraction b (format 'a/b' or 'a'): ";
        std::cin >> b;

        std::cout << "\na = " << a << std::endl;
        std::cout << "b = " << b << std::endl;

        std::cout << "\na + b = " << a + b << std::endl;
        std::cout << "a - b = " << a - b << std::endl;
        std::cout << "a * b = " << a * b << std::endl;
        std::cout << "a / b = " << a / b << std::endl;

        std::cout << "\na == b: " << (a == b) << std::endl;
        std::cout << "a < b: " << (a < b) << std::endl;
        std::cout << "a >= b: " << (a >= b) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

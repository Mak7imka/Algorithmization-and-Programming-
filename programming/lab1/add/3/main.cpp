#include "integral.h"
#include <iostream>
#include <iomanip>

void printMenu(const char* title, const char* options[], int count) {
    std::cout << "\n" << title << ":\n";
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
    std::cout << "Ваш вибір (1-" << count << "): ";
}

int main() {
    MathFunction functions[] = {
        linear,
        quadratic,
        cubic,
        sinFunction
    };
    
    const char* functionNames[] = {
        "f(x) = x",
        "f(x) = x^2",
        "f(x) = x^3",
        "f(x) = sin(x)"
    };

    IntegrationMethod methods[] = {
        rectangleMethod,
        trapezoidMethod
    };
    
    const char* methodNames[] = {
        "Метод прямокутників",
        "Метод трапецій"
    };

    while (true) {
        printMenu("Доступні функції", functionNames, 4);
        int funcChoice;
        std::cin >> funcChoice;
        if (funcChoice < 1 || funcChoice > 4) {
            std::cout << "Некоректний вибір функції!\n";
            continue;
        }

        printMenu("Методи інтегрування", methodNames, 2);
        int methodChoice;
        std::cin >> methodChoice;
        if (methodChoice < 1 || methodChoice > 2) {
            std::cout << "Некоректний вибір методу!\n";
            continue;
        }

        double a, b;
        int n;
        std::cout << "Введіть нижню межу інтегрування (a): ";
        std::cin >> a;
        std::cout << "Введіть верхню межу інтегрування (b): ";
        std::cin >> b;
        std::cout << "Введіть кількість розбиттів (n): ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Кількість розбиттів повинна бути додатною!\n";
            continue;
        }

        double result = methods[methodChoice - 1](functions[funcChoice - 1], a, b, n);

        std::cout << "\nРезультати обчислення:\n";
        std::cout << "Функція: " << functionNames[funcChoice - 1] << std::endl;
        std::cout << "Метод: " << methodNames[methodChoice - 1] << std::endl;
        std::cout << "Межі інтегрування: [" << a << ", " << b << "]" << std::endl;
        std::cout << "Кількість розбиттів: " << n << std::endl;
        std::cout << "Значення інтеграла = " << std::fixed << std::setprecision(6) << result << std::endl;

        char cont;
        std::cout << "\nБажаєте продовжити? (y/n): ";
        std::cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }

    return 0;
}

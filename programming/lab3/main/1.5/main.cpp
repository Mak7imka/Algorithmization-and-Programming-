#include <iostream>

class IntegerSum {
private:
    int value;
    static int totalSum;

public:
    IntegerSum(int val) : value(val) {totalSum += val;}

    int getValue() const {return value;}

    static int getSum() {return totalSum;}
};

int IntegerSum::totalSum = 0;

int main() {

    IntegerSum num1(5);
    std::cout << "Object 1: " << num1.getValue() << std::endl;
    std::cout << "Current sum: " << IntegerSum::getSum() << std::endl;

    IntegerSum num2(10);
    std::cout << "\nObject 2: " << num2.getValue() << std::endl;
    std::cout << "Current sum: " << IntegerSum::getSum() << std::endl;

    IntegerSum num3(15);
    std::cout << "\nObject 3: " << num3.getValue() << std::endl;
    std::cout << "Current sum: " << IntegerSum::getSum() << std::endl;

    std::cout << "\nFinal sum of all objects: " << IntegerSum::getSum() << std::endl;

    return 0;
}
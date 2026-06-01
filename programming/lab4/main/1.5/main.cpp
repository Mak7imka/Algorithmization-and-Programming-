#include <iostream>
#include <string>
#include "utils.h"

int main() {
    // Масив int
    int intArr[] = {1, 2, 3, 4, 5};
    int sizeInt = 5;

    std::cout << "int array before swap: ";
    printArray(intArr, sizeInt);
    swapElements(intArr, 1, 3);
    std::cout << "after swapping 1 and 3: ";
    printArray(intArr, sizeInt);
    std::cout << "index of 4: " << findElement(intArr, sizeInt, 4) << std::endl;
    swapAdjacentPairs(intArr, sizeInt);
    std::cout << "after swapping adjacent pairs: ";
    printArray(intArr, sizeInt);

    std::cout << "-----------------------------\n";

    // Масив double
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    int sizeDouble = 4;

    std::cout << "double array before swap: ";
    printArray(doubleArr, sizeDouble);
    swapElements(doubleArr, 0, 2);
    std::cout << "after swapping 0 and 2: ";
    printArray(doubleArr, sizeDouble);
    std::cout << "index of 2.2: " << findElement(doubleArr, sizeDouble, 2.2) << std::endl;
    swapAdjacentPairs(doubleArr, sizeDouble);
    std::cout << "after swapping adjacent pairs: ";
    printArray(doubleArr, sizeDouble);

    std::cout << "-----------------------------\n";

    // Масив string
    std::string strArr[] = {"apple", "banana", "cherry", "date"};
    int sizeStr = 4;

    std::cout << "string array before swap: ";
    printArray(strArr, sizeStr);
    swapElements(strArr, 1, 2);
    std::cout << "after swapping 1 and 2: ";
    printArray(strArr, sizeStr);
    std::cout << "index of 'date': " << findElement(strArr, sizeStr, std::string("date")) << std::endl;
    swapAdjacentPairs(strArr, sizeStr);
    std::cout << "after swapping adjacent pairs: ";
    printArray(strArr, sizeStr);

    return 0;
}

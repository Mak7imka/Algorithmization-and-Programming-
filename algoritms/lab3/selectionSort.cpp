#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <string>

int findSmallestPosition(const std::vector<int>& list, int listLength, int startPosition) {
    int smallestPosition = startPosition;
    int smallestValue = list[startPosition];

    for (int i = startPosition + 1; i < listLength; ++i) {
        if (list[i] < smallestValue) {
            smallestPosition = i;
            smallestValue = list[i];
        }
    }
    return smallestPosition;
}

void selectionSort(std::vector<int>& list) {
    int listLength = list.size();

    for (int i = 0; i < listLength - 1; ++i) {
        int smallestPosition = findSmallestPosition(list, listLength, i);
        std::swap(list[i], list[smallestPosition]);
    }
}


int main() {
    std::vector<int> unsortedList;
    std::string input;

    std::cout << "Введіть масив чисел (через пробіл): ";
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        unsortedList.push_back(number);
    }

    std::cout << "Несортований масив: ";
    for (int val : unsortedList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    selectionSort(unsortedList);

    std::cout << "\nВідсортований масив: ";
    for (int num : unsortedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

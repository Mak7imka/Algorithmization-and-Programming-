#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <string>

void bubbleSort(std::vector<int>& list) {
    int listLength = list.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < listLength - 1; ++i) {
            if (list[i] > list[i + 1]) {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
        listLength--;
    } while (swapped);
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

    bubbleSort(unsortedList);

    std::cout << "\nВідсортований масив: ";
    for (int val : unsortedList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

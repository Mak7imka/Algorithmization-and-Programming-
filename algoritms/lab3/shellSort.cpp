#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <string>

void shellSort(std::vector<int>& list) {
    int n = list.size();
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; i++) {
            int temp = list[i];
            int j;
            for (j = i; j >= step && list[j - step] > temp; j -= step) {
                list[j] = list[j - step];
            }
            list[j] = temp;
        }
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

    shellSort(unsortedList);

    std::cout << "\nВідсортований масив: ";
    for (int val : unsortedList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

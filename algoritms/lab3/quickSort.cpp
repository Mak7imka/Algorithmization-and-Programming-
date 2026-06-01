#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <string>

int partition(std::vector<int>& list, int start, int pivot_index) {
    int pivot_value = list[pivot_index];
    int i = start - 1;

    for (int j = start; j < pivot_index; ++j) {
        if (list[j] < pivot_value) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[pivot_index]);
    return i + 1; 

}

void quickSort(std::vector<int>& list, int start, int end) {
    if (start < end) {
        int pivot_index = end;

        int pivot_new_index = partition(list, start, pivot_index);

        quickSort(list, start, pivot_new_index - 1);

        quickSort(list, pivot_new_index + 1, end);
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

    quickSort(unsortedList, 0, unsortedList.size() - 1);

    std::cout << "\nВідсортований масив: ";
    for (int num : unsortedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

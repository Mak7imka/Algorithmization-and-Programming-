#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <string>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++; 
        }
        arr[j + 1] = key; 
    }
  std::cout << "Кількість обмінів (переміщень): " << swaps << std::endl;

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

    insertionSort(unsortedList);

    std::cout << "\nВідсортований масив: ";
    for (int num : unsortedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    
    return 0;
}
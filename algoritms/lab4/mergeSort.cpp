#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void merge(std::vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    std::cout << "Результат злиття [" << start << ", " << end << "]: ";
    for (int l = start; l <= end; ++l) {
        std::cout << arr[l] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(std::vector<int>& arr, int start, int end) {
    std::cout << "mergeSort викликано для підмасиву [" << start << ", " << end << "]" << std::endl;
    if (start < end) {
        int mid = start + (end - start) / 2;

        std::cout << "Розділення на [" << start << ", " << mid << "] та [" << mid + 1 << ", " << end << "]" << std::endl;

        mergeSort(arr, start, mid);

        mergeSort(arr, mid + 1, end);

        std::cout << "Злиття підмасивів [" << start << ", " << mid << "] та [" << mid + 1 << ", " << end << "]" << std::endl;
        merge(arr, start, mid, end);
    }
    std::cout << "\nВихід з mergeSort для підмасиву [" << start << ", " << end << "]" << std::endl;
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
    std::cout << "\n" << std::endl;

    mergeSort(unsortedList, 0, unsortedList.size() - 1);

    std::cout << "\nВідсортований масив: ";
    for (int val : unsortedList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
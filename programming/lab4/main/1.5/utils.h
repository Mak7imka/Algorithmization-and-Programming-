#ifndef UTILS_H
#define UTILS_H

#include <iostream>

template<typename T>
void swapElements(T* arr, int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<typename T>
int findElement(T* arr, int size, const T& value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

template<typename T>
void swapAdjacentPairs(T* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        swapElements(arr, i, i + 1);
    }
}

template<typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

#endif 

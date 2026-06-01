#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>

template <typename T>
T findMinElement(const T* arr, int size) {
    if (size <= 0)
        throw std::invalid_argument("Array is empty");

    T min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

#endif 



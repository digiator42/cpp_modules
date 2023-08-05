#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printElement(T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void iter(T* array, size_t length,  void(*fn)(T const&)) {
    for (size_t i = 0; i < length; i++) {
        fn(array[i]);
    }
}

#endif
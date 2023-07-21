#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), length(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : length(n) {
    elements = new T[length];
}

template<typename T>
Array<T>::Array(const Array& other) : length(other.length) {
    elements = new T[length];
    for (unsigned int i = 0; i < length; i++) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements;
        length = other.length;
        elements = new T[length];
        for (unsigned int i = 0; i < length; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw std::exception();
    }
    return elements[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return length;
}

#endif

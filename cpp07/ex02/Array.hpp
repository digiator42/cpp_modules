#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
private:
    T* elements;
    unsigned int length;

public:

    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);

    ~Array();

    T& operator[](unsigned int index);
    T& operator[](unsigned int index) const;

    unsigned int size() const;
};


#include "Array.tpp"

#endif
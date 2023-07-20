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

    // Destructor
    ~Array();

    // Subscript operator
    T& operator[](unsigned int index);

    // Size function
    unsigned int size() const;
};


#endif
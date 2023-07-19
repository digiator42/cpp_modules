#include <iostream>
#include <exception>

template<typename T>
class Array {
private:
    T* elements;
    unsigned int length;

public:

    Array() : elements(NULL), length(0) {}

    Array(unsigned int n) : length(n) {
        elements = new T[length];
    }

    Array(const Array& other) : length(other.length) {
        elements = new T[length];
        for (unsigned int i = 0; i < length; i++) {
            elements[i] = other.elements[i];
        }
    }

    Array& operator=(const Array& other) {
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

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= length) {
            throw std::exception();
        }
        return elements[index];
    }

    // Size function
    unsigned int size() const {
        return length;
    }
};

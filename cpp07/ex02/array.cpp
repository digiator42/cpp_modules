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

int main() {

    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i + 1;
    }
    
    Array<int> arr2 = arr1;
    
    Array<int> arr3;
    arr3 = arr1;
    
    std::cout << "Array 1: ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2: ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 3: ";
    for (unsigned int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

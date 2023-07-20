#include "Array.hpp"

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
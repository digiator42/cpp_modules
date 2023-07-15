#include <iostream>


template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Printing intArray: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Printing doubleArray: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    std::string str = "TEMPLATE";
    size_t strLength = str.length();

    std::cout << "Printing doubleArray: ";
    iter(str.c_str(), strLength, printElement<char>);
    std::cout << std::endl;

    return 0;
}

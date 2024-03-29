#include "Serialize.hpp"
#include <iostream>

int main() {
    data_t originalData;
    data_t* ptr = &originalData;

    ptr->str = "Hello, world!";

    uintptr_t serialized = Serializer::serialize(ptr);
    data_t* deserialized = Serializer::deserialize(serialized);

    // std::cout << "Original data: " << ptr->str << std::endl;

    if (ptr == deserialized) {
        std::cout << "DeSerializer successful. Pointers match." << std::endl;
    } else {
        std::cout << "DeSerializer failed. Pointers do not match." << std::endl;
    }
    
    
    std::endl(std::cout);

    data_t foo;
    uintptr_t reinterpreted;

    foo.str = std::string("test");
    reinterpreted = Serializer::serialize(&foo);

    std::cout << "foo Address = " << &foo << std::endl;
    std::cout << "Reinterpreted foo value = " << reinterpreted << std::endl;

    data_t *deserialized2;

    deserialized2 = Serializer::deserialize(reinterpreted);

    std::cout << "Deserialized2 Address = " << deserialized2 << std::endl;
    return 0;
}


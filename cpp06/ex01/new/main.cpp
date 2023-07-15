#include "Serialization.hpp"
#include <iostream>


int main() {
    data_t originalData;
    data_t* ptr = &originalData;
    ptr->dummy_str = "Hello, world!";

    uintptr_t serialized = Serialization::serialize(ptr);
    data_t* deserialized = Serialization::deserialize(serialized);

    std::cout << "Original data: " << ptr->dummy_str << std::endl;

    if (ptr == deserialized) {
        std::cout << "Deserialization successful. Pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    }
    
    
    std::endl(std::cout);

    data_t foo;
    uintptr_t reinterpreted;

    foo.dummy_str = std::string("test");
    reinterpreted = Serialization::serialize(&foo);

    std::cout << "foo Address = " << &foo << std::endl;
    std::cout << "dummy_str value = " << foo.dummy_str << std::endl;
    std::cout << "Reinterpreted foo value = " << reinterpreted << std::endl;

    data_t *deserialized2;

    deserialized2 = Serialization::deserialize(reinterpreted);

    std::cout << "Deserialized2 Address = " << deserialized2 << std::endl;
    std::cout << "dummy_str value = " << deserialized2->dummy_str << std::endl;
    return 0;
}

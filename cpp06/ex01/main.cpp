#include "serialize.hpp"

int main() {
    Data originalData(42);
    Data* ptr = &originalData;

    uintptr_t serialized = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Original data: " << ptr->getData() << std::endl;
    std::cout << "Deserialized data: " << deserialized->getData() << std::endl;

    if (ptr == deserialized) {
        std::cout << "Deserialization successful. Pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    }

    return 0;
}

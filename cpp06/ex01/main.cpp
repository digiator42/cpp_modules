#include "serialize.hpp"

using namespace std;

int main() {
    // data_t originalData;
    // data_t* ptr = &originalData;
    // ptr->str = "Hello, world!";

    // uintptr_t serialized = Serializer::serialize(ptr);
    // data_t* deserialized = Serializer::deserialize(serialized);

    // std::cout << "Original data: " << ptr->str << std::endl;

    // if (ptr == deserialized) {
    //     std::cout << "Deserialization successful. Pointers match." << std::endl;
    // } else {
    //     std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    // }


    data_t foo;
    uintptr_t reinterpreted;

    foo.str = std::string("test");
    reinterpreted = Serializer::serialize(&foo);

    cout << "OG foo (Data) Address = " << &foo << endl
         << "str value = " << foo.str << endl;

    cout << endl;

    cout << "Reinterpreted foo value = " << reinterpreted << endl;

    cout << endl;

    data_t *deserialized;

    deserialized = Serializer::deserialize(reinterpreted);

    cout << "Deserialized Address = " << deserialized << endl
         << "str value = " << deserialized->str << endl;
    return 0;
}

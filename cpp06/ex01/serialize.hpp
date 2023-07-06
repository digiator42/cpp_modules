#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <cstdint>


class Data {
public:
    Data(int value) : data(value) {}
    int getData() const { return data; }

private:
    int data;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
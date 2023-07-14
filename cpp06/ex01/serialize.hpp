#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"
#include <iostream>
#include <cstdint>

class Serializer {
public:
    static uintptr_t serialize(data_t* ptr);
    static data_t* deserialize(uintptr_t raw);
};

#endif
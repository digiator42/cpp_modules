#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

class Serializer {
	public:
		static uintptr_t serialize(data_t *ptr);
		static data_t *deserialize(uintptr_t raw);
};

#endif

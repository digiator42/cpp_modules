#include "Weapon.hpp"

Weapon::Weapon(std::string const &type):_type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type)
{
	_type = type;
}

std::string const Weapon::getType() const
{
	return this->_type;
}
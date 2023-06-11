#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

Weapon *HumanB::getWeapon() const
{
	return this->_weapon;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->getWeapon()->getType() << std::endl;
}

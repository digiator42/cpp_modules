#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)  :
	_name(name), ـweapon(weapon)
{
}

HumanA::~HumanA() {}

Weapon &HumanA::getWeapon() const
{
	return ـweapon;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->getWeapon().getType() << std::endl;
}

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &ـweapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		Weapon &getWeapon() const;
	
	void attack();
};
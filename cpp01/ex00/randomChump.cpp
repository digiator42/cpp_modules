#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *zombie = new Zombie;
	zombie->setName(name);
	zombie->announce();
	delete zombie;
}
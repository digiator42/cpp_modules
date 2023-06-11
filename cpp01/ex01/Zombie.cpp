#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "default Zombie";
}

Zombie::~Zombie()
{
	std::cout << "Destructor: ";
	std::cout << _name << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];

	while (N--)
		zombie[N].setName(name);

	return zombie;	
}

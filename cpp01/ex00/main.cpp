#include "Zombie.hpp"

int main()
{
	Zombie zombie;
	zombie.announce();
	zombie.setName("ZZZzzzz");
	zombie.announce();
	std::cout << "----------" << std::endl;

	Zombie *zombie2 = newZombie("newZombie");
	zombie2->announce();
	std::cout << "----------" << std::endl;
	zombie2->setName("NNNnnnn");
	zombie2->announce();
	std::cout << "----------" << std::endl;
	delete zombie2;

	std::cout << "----------" << std::endl;
	randomChump("zomieeeee");
}
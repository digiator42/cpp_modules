#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		size_t i;
		Harl Harl;
		std::string levels[4] = {"DEBUG", "INFO" ,"WARNING", "ERROR"};

		for (i = 0; i < levels->length(); i++)
		{
			if(av[1] == levels[i])
				break;
		}
		switch (i)
		{
		case 0:
			Harl.complain(levels[i]);
				break;
		case 1:
			Harl.complain(levels[i]);
				break;
		case 2:
			Harl.complain(levels[i]);
				break;
		case 3:
			Harl.complain(levels[i]);
				break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
		return 0;
	}
	return 0;
}
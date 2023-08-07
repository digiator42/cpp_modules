#include "Easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> array;

	int i = 0;
	while (i < 10)
		array.push_back(i++);

	try {
		std::vector<int>::iterator it = easyFind(array, i);
		std::cout << *it << std::endl;
	} catch(std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
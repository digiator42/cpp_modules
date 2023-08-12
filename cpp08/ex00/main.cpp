#include "easyfind.hpp"
#include <vector>
#include <iterator>
#include <iostream>

int main() {

	std::vector<int> vector;
	std::list<int> list;
	std::set<int> set;
	std::map<int, std::string> map;

	int i = 0;
	while (i < 10) {
		vector.push_back(i);
		list.push_front(vector[i]);
		set.insert(vector[i++]);
		std::string s(1, '0' + i);
		map.insert(std::make_pair(i, "hello " + s));
	}

	try {

		if (easyFind(vector, --i))
			std::cout << vector.at(i) << std::endl;

		if (easyFind(list, i)) {
			std::list<int>::iterator lit = list.begin();
			for (int j = 0; j < i; ++j) {
    			++lit;
			}
			std::cout << *lit << std::endl;
		}

		if(easyFind(set, i)) {
			std::set<int>::iterator sit = set.begin();
			std::advance(sit, i);
			std::cout << *sit << std::endl;
		}


		if (easyFind(map, i))
			std::cout << map.at(i) << std::endl;

	} catch(std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

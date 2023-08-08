#include "Easyfind.hpp"
#include <vector>
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
		map.insert(std::make_pair(i, "hello " + std::to_string(i)));
	}

	try {

		std::vector<int>::iterator v = easyFind(vector, --i);
		std::cout << *v << std::endl;

		std::list<int>::iterator l = easyFind(list, i);
		std::cout << *l << std::endl;
		
		std::set<int>::iterator seit = easyFind(set, i);
		std::cout << *seit << std::endl;


		std::map<int, std::string>::iterator s = easyFind(map, i);
		std::cout << s->first << " " << s->second << std::endl;

	} catch(std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

#include <iostream>
#include <algorithm>
#include <map>



// find element in container
template<typename Container, typename T>
bool easyFind(Container &container, const T &toFind) {
    if (std::find(container.begin(), container.end(), toFind) != container.end())
		return true;

    throw std::runtime_error("couldn't find element");
}

// find element in map
template<typename Key, typename Value>
bool easyFind(std::map<Key, Value> &container, const Key &toFind) {
    if (container.find(toFind) != container.end())
        return true;
    throw std::runtime_error("couldn't find element");
}


#include <iostream>
#include <map>
#include <list>
#include <set>


// find element in container
template<typename Container, typename T>
typename Container::iterator easyFind(Container &container, const T &toFind) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        if (*it == toFind) {
            return it;
        }
    }
    throw std::runtime_error("couldn't find element");
}

// find element in map
template<typename Key, typename Value>
typename std::map<Key, Value>::iterator easyFind(std::map<Key, Value> &container, const Key &toFind) {
    typename std::map<Key, Value>::iterator it = container.begin();
    for (; it != container.end(); ++it) {
        if (it->first == toFind) {
            return it;
        }
    }
    throw std::runtime_error("couldn't find element");
}

// find element in container
template<typename Key, typename Value>
typename std::set<int>::iterator easyFind(std::set<int> &container, const Key &toFind) {
    typename std::set<int>::iterator it = container.begin();
    for (; it != container.end(); ++it) {
        if (*it == toFind) {
            return it;
        }
    }
    throw std::runtime_error("couldn't find element");
}


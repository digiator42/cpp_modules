#include <iostream>


template<typename Container, typename T>
typename Container::iterator easyFind(Container &container, const T &toFind) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        if (*it == toFind) {
            return it;
        }
    }
    throw std::runtime_error("couldn't find element");
}
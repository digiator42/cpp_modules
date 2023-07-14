#include "Dynamic.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));
    Base* obj1 = generate();
    identify(obj1);
    delete obj1;

    Base* obj2 = generate();
    identify(*obj2);
    delete obj2;

    Base* obj3 = generate();
    identify(*obj3);
    delete obj3;

    return 0;
}

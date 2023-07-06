
#include "dynamic.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));

    Base* obj1 = generate();
    identify(obj1);
    delete obj1;

    Base* obj2 = generate();
    identify(*obj2);
    delete obj2;

    return 0;
}

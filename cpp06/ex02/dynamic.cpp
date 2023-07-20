#include "Dynamic.hpp"

Base* generate() {
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {   
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
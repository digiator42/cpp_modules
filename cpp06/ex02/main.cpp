#include "Dynamic.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));


    std::cout << "polymorphism\n";

    Base *arr[3] = { generate(), 
                     generate(), 
                     generate()
                    };

    for (int i = 0; i < 3; i++) {
        identify(*arr[i]);
        delete arr[i];
    }
    return 0;
}


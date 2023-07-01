#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Madam none", 50);
        std::cout << bureaucrat << std::endl;

        Bureaucrat bureaucrat2("Madam none", 30);
        std::cout << bureaucrat2 << std::endl;
        
        Bureaucrat highGradeBureaucrat("Madam none", 0); // <-- Exception

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        }

    return 0;
}

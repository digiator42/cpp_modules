#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Madam Samah", 50);
        std::cout << bureaucrat << std::endl;

        Bureaucrat bureaucrat2("Madam Ragaa", 30);
        std::cout << bureaucrat2 << std::endl;
        
        Bureaucrat highGradeBureaucrat("Madam Ragaa", 0); // <-- Exception

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        }

    return 0;
}

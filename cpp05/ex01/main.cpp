#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Madam Samah", 50);
        std::cout << bureaucrat << std::endl;

        Form form("Form 1", 60, 70);
        std::cout << form << std::endl;

        try {
            form.beSigned(bureaucrat);
            std::cout << form << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Bureaucrat highGradeBureaucrat("Madam Ragaa", 30);
        std::cout << highGradeBureaucrat << std::endl;

        try {
            form.beSigned(highGradeBureaucrat);
            std::cout << form << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

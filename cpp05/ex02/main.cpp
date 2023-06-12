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


    std::cout << "               ,@@@@@@@," << std::endl;
    std::cout << "       ,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl;
    std::cout <<"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"  << std::endl;
    std::cout <<"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"  << std::endl;
    std::cout <<"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"  << std::endl;
    std::cout <<"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"  << std::endl;
    std::cout <<"   `&%\\ ` /%&'    |.|        \\ '|8'"  << std::endl;
    std::cout <<"       |o|        | |         | |"  << std::endl;
    std::cout <<"       |.|        | |         | |"  << std::endl;
    std::cout <<"   \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"  << std::endl;
    return 0;
}

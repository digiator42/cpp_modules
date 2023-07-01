#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat0;
        std::cout << bureaucrat0 << std::endl;
        Bureaucrat bureaucrat("Madam one", 50);
        std::cout << bureaucrat << std::endl;
        Form form("form", 50, 50);
        std::cout << form << std::endl;
        bureaucrat.signForm(form);
        Bureaucrat bureaucrat2("Madam one", 30);
        std::cout << bureaucrat2 << std::endl;
        
        Bureaucrat highGradeBureaucrat("Madam one", 0); // <-- Exception

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat2("Madam one", 50);
        std::cout << bureaucrat2 << std::endl;
        Form form("form", 45, 55);
        std::cout << form << std::endl;
        bureaucrat2.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

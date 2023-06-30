#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    
    try
    {
        Bureaucrat bureaucrat("Madam Samah", 45);

        Intern intern;
        AForm *form[3] = {
            intern.makeForm("ShrubberyCreationForm", "FOUND"),
            intern.makeForm("RobotomyRequestForm", "FOUND"),
            intern.makeForm("PresidentialPardonForm", "FOUND"),
        };
        for (size_t i = 0; i < 3; i++)
            std::cout << form[i]->getName() + '\n';

        bureaucrat.signForm(*form[0]);
        
        intern.makeForm("NOT-VALID", "NV"); // Exception: Form Not Found
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    return 0;
}

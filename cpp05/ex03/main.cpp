#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    
    try
    {
        Bureaucrat bureaucrat("Madam one", 45);

        Intern intern;
        AForm *form[3] = {
            intern.makeForm("shrubbery request", "FOUND"),
            intern.makeForm("robotomy request", "FOUND"),
            intern.makeForm("presidential request", "FOUND")
        };
        for (size_t i = 0; i < 3; i++)
            std::cout << "Form Name: " << form[i]->getName() + '\n';
        bureaucrat.signForm(*form[0]);
        for (size_t i = 0; i < 3; i++)
            delete form[i];
        
        intern.makeForm("NOT-VALID", "NV"); // Exception: Form Not Found
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    return 0;
}

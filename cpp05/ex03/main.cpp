#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main() {
    
    
    Bureaucrat bureaucrat("Madam Samah", 45);

    Intern intern;
    AForm *found;
    // AForm *notFound;
    found = intern.makeForm("ShrubberyCreationForm", "FOUND");


    found->beSigned(bureaucrat);
    found->execute(bureaucrat);

    std::cout << found->getName() + '\n';
    
    // notFound = intern.makeForm("NOT-VALID", "NV"); //exception
    // notFound->beSigned(bureaucrat);
    // notFound->execute(bureaucrat);
    return 0;
}

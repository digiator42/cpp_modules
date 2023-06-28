#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main() {
    
    
    Bureaucrat bureaucrat("Madam Samah", 44);

    Intern intern;
    AForm *sh;
    sh = intern.makeForm("ShrubberyCreationForm", "NI");

    sh->beSigned(bureaucrat);
    sh->execute(bureaucrat);
    
    return 0;
}

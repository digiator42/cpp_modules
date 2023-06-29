#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try {

        Bureaucrat bureaucrat("Madam Samah", 146);
        ShrubberyCreationForm sform("target1");
        bureaucrat.signForm(sform);
        ShrubberyCreationForm sform2;
        // sform2 = sform;
        // std::cout << sform << std::endl;
        // std::cout << sform2 << std::endl;
        // std::cout << (sform2.isFormSigned() && sform.isFormSigned() ?  "TRUE" : "FALSE") << std::endl;

        // bureaucrat.executeForm(sform);
        
        // Bureaucrat bureaucrat2("Madam Samah", 0); // Exception

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        }

    return 0;
}

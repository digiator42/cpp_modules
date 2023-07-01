#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try {
        Bureaucrat bureaucrat0;
        std::cout << bureaucrat0 << std::endl;
        PresidentialPardonForm pform("target0");
        bureaucrat0.signForm(pform);
        bureaucrat0.executeForm(pform);
        std::cout << pform << std::endl;

        Bureaucrat bureaucrat10;
        std::cout << bureaucrat10 << std::endl;
        PresidentialPardonForm dform("target10");
        bureaucrat0.signForm(dform);
        bureaucrat0.executeForm(dform);
        std::cout << dform << std::endl;

        
        Bureaucrat bureaucrat("Madam one", 45);
        ShrubberyCreationForm sform("target1");
        bureaucrat.signForm(sform);
        ShrubberyCreationForm sform2;
        std::cout << sform2 << std::endl;
        sform2 = sform;
        std::cout << sform << std::endl;
        std::cout << sform2 << std::endl;
        std::cout << (sform2.isFormSigned() && sform.isFormSigned() ?  "TRUE" : "FALSE") << std::endl;

        bureaucrat.executeForm(sform);
        
        Bureaucrat bureaucrat2("Madam one", 0); // Exception

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        //execute grade for shrubbery should be < 137
        Bureaucrat bureaucrat("Madam two", 136);
        ShrubberyCreationForm sform("target1");
        bureaucrat.signForm(sform);
        bureaucrat.executeForm(sform);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
        

    return 0;
}

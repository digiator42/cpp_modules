#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::~Intern() {}


AForm* Intern::createShrubberyCreationForm(const std::string& target) {

    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {

    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {

    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFound::what() const throw() {
    return "Form Not Found";
}

AForm *Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string levels[3] = {"ShrubberyCreationForm", "RobotomyRequestForm" ,"PresidentialPardonForm"};

    AForm *(Intern::*f[3])(const std::string&) = { &Intern::createShrubberyCreationForm, 
                                                &Intern::createRobotomyRequestForm,
                                                &Intern::createPresidentialPardonForm
                                                };

	for (size_t i = 0; i < levels->length(); i++)
        return formName == levels[i] ? (this->*f[i])(target) : throw Intern::FormNotFound();  
	throw Intern::FormNotFound();
}
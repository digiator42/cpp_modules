#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137), _target(target) {
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    !isFormSigned() ? throw FormNotSignedException() : (executor.getGrade() > getExecGrade() ? 
        throw GradeTooLowException() : (void)0);

    std::ofstream outfile("Shrubbery_" + getName());
    std::string tree = "              ,@@@@@@@,\n"
                   "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                   " ,&%%&%&&%,@@@@@/@@@@@@,8888\\\\88/8o\n"
                   ",%&\\\\%&&%&&%,@@@\\\\@@@/@@@88\\\\88888/88\\\n"
                   "%&&%&%&/%&&%@@\\\\@@/ /@@@88888\\\\88888\\\n"
                   "%&&%/ %&%%&&@@\\\\ V /@@' `88\\\\8 `/88'\n"
                   "`&%\\\\ ` /%&'    |.|        \\\\ '|8'\n"
                   "    |o|        | |         | |\n"
                   "    |.|        | |         | |\n"
                   "\\/ ._\\\\//_/__/  ,\\\\_//__\\\\/.  \\\\_//__/_";

    if (outfile.is_open()) {
        outfile << tree << std::endl;
    outfile.close();
    } else {
        throw FileOpenException();
    }
}
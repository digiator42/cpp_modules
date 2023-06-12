#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137) {
        (void)target;
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
    if (!isFormSigned())
        throw FormNotSignedException();

    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::ofstream outfile(getName() + "_shrubbery");
    if (outfile.is_open()) {
        outfile << "ASCII trees here!" << std::endl;
        outfile.close();
    } else {
        throw FileOpenException();
    }
}
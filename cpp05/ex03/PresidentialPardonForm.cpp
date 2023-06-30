#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5) {
        (void)target;
    }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {

    if (!isFormSigned()) {
        throw FormNotSignedException();
    } else if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    std::cout << getTarget() << " has been pardoned by chatGPT." << std::endl;
}

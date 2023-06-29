#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
    }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    !isFormSigned() ? throw Bureaucrat::FormNotSignedException() : (executor.getGrade() > getExecGrade() ? 
        throw GradeTooLowException() : (void)0);

    std::cout << "Drilling noises..." << std::endl;
    std::srand(std::time(NULL));
    int random = std::rand() % 2;

    std::cout << random << std::endl;

    if (random == 0)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << getTarget() << "!" << std::endl;
}

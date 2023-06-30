#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
        : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
   
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isFormSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName() << " [Sign Grade: " << form.getSignGrade() << ", Exec Grade: "
        << form.getExecGrade() << ", Signed: " << (form.isFormSigned() ? "Yes" : "No") << "]";
    return out;
}

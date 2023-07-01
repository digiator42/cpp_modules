#include "Form.hpp"

Form::Form(): name("Default"), isSigned(false), signGrade(1), execGrade(1) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
        : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
   
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), execGrade(other.execGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& Form::getName() const {
    return name;
}

bool Form::isFormSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecGrade() const {
    return execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName() << " [Sign Grade: " << form.getSignGrade() << ", Exec Grade: "
        << form.getExecGrade() << ", Signed: " << (form.isFormSigned() ? "Yes" : "No") << "]";
    return out;
}

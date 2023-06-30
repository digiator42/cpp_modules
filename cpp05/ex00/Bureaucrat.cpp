#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(0) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {

    grade < 1 ? 
        throw GradeTooHighException() : 
    (grade > 150 ? 
        throw GradeTooLowException() : this->grade = grade);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj) {
    if (this != &obj)
    {
        grade < 1 ? 
            throw GradeTooHighException() : 
        grade > 150 ? 
            throw GradeTooLowException() : (void)0;
    }
    this->grade = obj.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150) {
        throw GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

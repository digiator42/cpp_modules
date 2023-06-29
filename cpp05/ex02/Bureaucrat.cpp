#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    grade < 1 ? throw GradeTooHighException() : (grade > 150 ? 
        throw GradeTooLowException() : this->grade = grade);
    (void)grade;
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

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() + " couldn't sign " + form.getName() << " because " << e.what() << std::endl;
    }
    
    std::cout << (form.isFormSigned() ? (getName() + " signed form " + form.getName() + "\n") 
        : throw FormNotSignedException() );
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
    } catch (std::exception& e) {
        std::cerr << this->getName() + " couldn't sign " + form.getName() << std::endl;
    }
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

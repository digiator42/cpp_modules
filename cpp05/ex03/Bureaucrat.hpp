#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
            const char* what() const throw() {
                return "Exception: Form is not signed.";
            }
    };

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(Bureaucrat const &obj);
    Bureaucrat &operator=(Bureaucrat const &obj);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif

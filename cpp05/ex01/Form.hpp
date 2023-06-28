#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
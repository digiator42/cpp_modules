#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    
    public:
        Form();
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        ~Form();
    
        Form& operator=(const Form& other);
    
        const std::string& getName() const;
        bool isFormSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
    
        void beSigned(const Bureaucrat& bureaucrat);
    
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
    };

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif

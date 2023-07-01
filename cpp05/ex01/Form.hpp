#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    
    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        ~AForm();
    
        AForm& operator=(const AForm& other);
    
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

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif

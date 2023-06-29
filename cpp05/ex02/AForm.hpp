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
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        virtual ~AForm();
    
        AForm& operator=(const AForm& other);
    
        const std::string& getName() const;
        bool isFormSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
    
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;
    
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class FileOpenException : public std::exception {
        public:
            const char* what() const throw() {
                return "Exception: File cann't be opnened.";
            }
        };
    };

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif

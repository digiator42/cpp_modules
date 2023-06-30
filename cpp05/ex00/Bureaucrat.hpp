#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>


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

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif

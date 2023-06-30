#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    class FormNotFound : public std::exception { 
        public:
            const char* what() const throw(); 
    };

    // Constructor
    Intern();
    Intern(Intern const & intern);
    Intern & operator=(Intern const & obj);
    // Destructor
    ~Intern();

    // Function to create a AForm
    AForm* makeForm(const std::string& formName, const std::string& target);

    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);
};

#endif

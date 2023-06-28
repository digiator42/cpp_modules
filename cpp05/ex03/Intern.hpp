#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <map>

class Intern {
public:
    // Constructor
    Intern();

    // Destructor
    ~Intern();

    // Function to create a AForm
    AForm* makeForm(const std::string& formName, const std::string& target) ;

    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);
};

#endif

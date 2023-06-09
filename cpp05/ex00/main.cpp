#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat b1("John", 150);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;
        //throws exception
        Bureaucrat b2("Alice", 0);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Alice", 151);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}

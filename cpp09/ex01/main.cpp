#include "RPN.hpp"

int main(int argc, char *argv[])
{
    
    try {
        if (argc != 2) {
            throw std::invalid_argument("Error: Invalid input");
        }
        RPN rpn = RPN();
        rpn.execute(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

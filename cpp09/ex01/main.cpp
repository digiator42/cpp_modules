#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid input " << std::endl;
        return (1);
    }
    
    try {
        RPN testcase = RPN();
        testcase.execute(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

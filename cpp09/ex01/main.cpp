#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid input " << std::endl;
        return (1);
    }
    
    RPN testcase = RPN();
    testcase.execute(argv[1]);
}

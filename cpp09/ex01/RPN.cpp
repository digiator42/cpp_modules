#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) {
    *this = copy;
}

RPN& RPN::operator=(const RPN & other) {
    return *this;
}

void    RPN::execute(char *expression) {
    std::stack<int>     stack;
    std::string         input;
    int                 digit;

    std::stringstream ss(expression);

    while (ss >> input) {
        if (input == "+" || input == "-" || input == "*" || input == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error: invalid expression " << std::endl;
                exit(1);
            }

            int firstInt = stack.top();
            stack.pop();
            int secondInt = stack.top();
            stack.pop();


            if (input == "+")
                stack.push(firstInt + secondInt);
            else if (input == "-")
                stack.push(secondInt - firstInt);
            else if (input == "*")
                stack.push(firstInt * secondInt);
            else if (input == "/")
                stack.push(firstInt / secondInt);

        }
        else if (input == "(" || input == ")") {
            std::cerr << "Error: Bad input " << std::endl;
            exit(1);
        }
        else if (isdigit(input[0])) {
            digit = atoi(input.c_str());
            stack.push(digit);
        }
        else {
            std::cerr << "Error: invalid int " << std::endl;
            exit(1);
        }
        ss >> std::ws;
    }
    std::cout << stack.top() << std::endl;
}

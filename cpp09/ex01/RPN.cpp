#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) {
    *this = copy;
}

RPN& RPN::operator=(const RPN & other) {
    (void)other;
    return *this;
}

void    RPN::execute(char *expression) {
    std::stack<int>     stack;
    std::string         input;
    int                 digit;

    std::stringstream ss(expression);
    input = expression;
    if (input.find_first_not_of("0123456789 -+*/") != std::string::npos)
        throw std::runtime_error("Invalid expression");
    while (ss >> input) {
        if (input == "+" || input == "-" || input == "*" || input == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Error: invalid expression ");

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
        else if (isdigit(input[0]) && input.find_first_not_of("0123456789") == std::string::npos) {
            digit = atoi(input.c_str());
            stack.push(digit);
        }
        else
            throw std::runtime_error("Error: invalid integer");
    }
    if (stack.size() >= 2)
        throw std::runtime_error("Error: invalid expression");
    std::cout << stack.top() << std::endl;
}

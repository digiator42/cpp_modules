#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdlib.h>

class RPN
{
public:
    RPN();
    ~RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN & other);

    void    execute(char *expression);
};

#endif
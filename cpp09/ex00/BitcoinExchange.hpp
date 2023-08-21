#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits.h>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <sstream>


class BitcoinExchange
{
private:
    std::map<std::string, float> map;
    char *filePath;

public:
    BitcoinExchange();
    BitcoinExchange(char *filePath);
    ~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange & other);

    void    printMap();
    void    displayData();
	class exception : public std::exception
	{
		private:
			std::string err_msg;
		public:
			~exception() throw() {}
			exception(std::string msg) : err_msg(msg) {}
			virtual const char *what() const throw();
	};
};

#endif
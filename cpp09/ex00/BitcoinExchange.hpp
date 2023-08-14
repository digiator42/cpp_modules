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


class Btc
{
private:
    std::map<std::string, float> map;
    char *filePath;

public:
    Btc();
    Btc(char *filePath);
    ~Btc();
	Btc(const Btc& copy);
	Btc& operator=(const Btc & other);

    void    printMap();
    void    displayData();
	class exception : public std::exception
	{
		private:
			std::string err_msg;
		public:
			~exception() throw() {}
			exception(std::string msg) : err_msg(msg) {}
			virtual const char *what() const throw() {
				return err_msg.c_str();
			}
	};
};

#endif
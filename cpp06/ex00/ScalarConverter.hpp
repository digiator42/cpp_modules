#ifndef SCALAR_CONVERTOR_H
#define SCALAR_CONVERTOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <string>
#include <cstdlib>
#include <sstream>


class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator=(ScalarConverter const &obj);
		~ScalarConverter();
		static bool isValidFormat(std::string s);
		static double _stoi(std::string s);
		static void toChar(std::string s);
		static void toInt(std::string s);
		static void toFloat(std::string s);
		static void toDouble(std::string s);

	public:
		static void convert(std::string& literal);
};

#endif
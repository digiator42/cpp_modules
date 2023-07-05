#ifndef SCALAR_CONVERTOR_H
#define SCALAR_CONVERTOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <sstream>

class ScalarConverter {

	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator=(ScalarConverter const &obj);
		~ScalarConverter();

		void convert(const std::string& literal);
		bool isValidFormat(std::string s);
		float _stoi(std::string s);
		void toChar(std::string s);
		void toInt(std::string s);
		void toFloat(std::string s);
		void toDouble(std::string s);
};

#endif
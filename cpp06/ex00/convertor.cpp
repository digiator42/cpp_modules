#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <climits>
#include <sstream>


int _stoi(std::string s)
{
    std::istringstream iss(s);
    int value;
    if (!(iss >> value)) {
        // Failed to convert
        throw std::invalid_argument("Invalid conversion");
    }
    // std::cout << "value: " << value << std::endl;
    return value;
}

bool isAllDigit(std::string s)
{
    int counter = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '.' || s[i] == 'f')
            counter++;
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
            return false;
    }
    return counter > 2 ? false : true;
}


float parseFloat(std::string s)
{
    if (!isAllDigit(s)) {
        throw std::invalid_argument("Invalid float format");
    }
    // return static_cast<float>(atof(s.c_str()));
    return static_cast<float>(_stoi(s));
}



class ScalarConverter {
public:
    static void convert(const std::string& literal) {

        !isAllDigit(literal) ?
            throw std::invalid_argument("Worng Type") : (void)0;

        if (literal == "nan" || literal == "-inf" || literal == "+inf" 
            || literal == "-inff" || literal == "+inff" || literal == "nanf") {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << literal << "f\n";
            std::cout << "double: " << literal << "\n";
            return;
        }
        // to char
        try {
            if (_stoi(literal) > CHAR_MAX || _stoi(literal) < CHAR_MIN)
                throw std::invalid_argument("Invalid conversion");
            char charValue = static_cast<char>(_stoi(literal));
            if (isprint(charValue)) {
                std::cout << "char: '" << charValue << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        } catch (const std::exception&) {
            std::cout << "char: Conversion not possible" << std::endl;
        }

        // to int
        try {
            int intValue = static_cast<int>(_stoi(literal));
            std::cout << "int: " << intValue << std::endl;
        } catch (const std::exception&) {
            std::cout << "int: Conversion not possible" << std::endl;
        }

        // to float
		try {
            float floatValue = parseFloat(literal);
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        } catch (const std::exception&) {
            std::cout << "float: Conversion not possible" << std::endl;
        }

        // to double
        try {
            double doubleValue = static_cast<double>(parseFloat(literal));
            std::cout << "double: " << doubleValue << std::endl;
        } catch (const std::exception&) {
            std::cout << "double: Conversion not possible" << std::endl;
        }
    }
};

int main(int argc, char** argv) {

	if (argc != 2) {
		std::cout << "Usage: ./convertor <literal>" << std::endl;
		return 1;
	}
    ScalarConverter::convert(argv[1]);
    
    return 0;
}

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <sstream>


int _stoi(std::string s)
{
    std::stringstream ss(s);
    int n;
    ss >> n;
    return n;
}
int _stof(std::string s)
{
    std::stringstream ss(s);
    float n;
    ss >> n;
    return n;
}
int _stod(std::string s)
{
    std::stringstream ss(s);
    double n;
    ss >> n;
    return n;
}

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
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
            char charValue = _stoi(literal);
            std::cout << "int --> " << literal << std::endl;
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
            int intValue = _stoi(literal);
            std::cout << "int: " << intValue << std::endl;
        } catch (const std::exception&) {
            std::cout << "int: Conversion not possible" << std::endl;
        }

        // to float
		try {
            float floatValue = _stof(literal);
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        } catch (const std::exception&) {
            std::cout << "float: Conversion not possible" << std::endl;
        }

        // to double
        try {
            double doubleValue = _stod(literal);
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

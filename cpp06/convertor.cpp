#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
        // to char
        try {
            char charValue = static_cast<char>(std::stoi(literal));
            if (std::isprint(charValue))
                std::cout << "char: '" << charValue << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } catch (const std::exception&) {
            std::cout << "char: Conversion not possible" << std::endl;
        }

        // to int
        try {
            int intValue = std::stoi(literal);
            std::cout << "int: " << intValue << std::endl;
        } catch (const std::exception&) {
            std::cout << "int: Conversion not possible" << std::endl;
        }

        // to float
        try {
            float floatValue = std::stof(literal);
            std::cout << "float: " << floatValue << "f" << std::endl;
        } catch (const std::exception&) {
            std::cout << "float: Conversion not possible" << std::endl;
        }

		try {
            float floatValue = std::stof(literal);
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        } catch (const std::exception&) {
            std::cout << "float: Conversion not possible" << std::endl;
        }

        // to double
        try {
            double doubleValue = std::stod(literal);
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

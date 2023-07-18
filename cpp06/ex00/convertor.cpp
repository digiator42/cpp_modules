#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj){
    (void)obj;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj){
    (void)obj;
    return *this;
}

double ScalarConverter::_stoi(std::string s)
{
    std::istringstream iss(s);
    double value;
    if (!(iss >> value)) {
        // Failed to convert
        throw std::invalid_argument("Invalid conversion");
    }
    return value;
}

bool ScalarConverter::isValidFormat(std::string s)
{
    int dotCounter = 0;
    int fCounter = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (i == 0 && (s[i] == '+' || s[i] == '-'))
            i++;
        if (s[i] == '.')
            dotCounter++;
        if (s[i] == 'f')
            i == s.length() - 1 && i != 0 && dotCounter ? fCounter++ : fCounter += 2;
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
            return false;
    }
    return dotCounter > 1 || fCounter > 1 ? false : true;
}


void ScalarConverter::convert(std::string& literal) {

    if (literal == "nan" || literal == "-inf" || literal == "+inf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        literal.erase(literal.length() - 1);
        std::cout << "double: " << literal << "\n";
        return;
    }
    
    if (isalpha(literal[0]) && literal.length() == 1) { 
        std::cout << "char: '" << literal << "'\n";
        std::cout << "int: " << static_cast<int>(literal[0]) << "\n";
        std::cout << "float: " << static_cast<float>(literal[0]) << ".0" << "f\n";
        std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << "\n";
        return ;
    }

    try {
        !isValidFormat(literal) ?
            throw std::invalid_argument("Invalid Input") : (void)0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return ;
    }
    toChar(literal);
    toInt(literal);
    toFloat(literal);
    toDouble(literal);
}

// to int
void ScalarConverter::toInt(std::string s)
{
    try {
        if (s[s.length() - 1] == 'f')
            s.erase(s.length() - 1);
        if (_stoi(s) < std::numeric_limits<int>::min() || _stoi(s) > std::numeric_limits<int>::max())
            throw std::invalid_argument("Invalid conversion");
        int intValue = static_cast<int>(_stoi(s));
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "int: Conversion not possible" << std::endl;
    }

}
// to char
void ScalarConverter::toChar(std::string s)
{
    try {
        if (s[s.length() - 1] == 'f')
            s.erase(s.length() - 1);
        if (_stoi(s) < std::numeric_limits<char>::min() || _stoi(s) > std::numeric_limits<char>::max())
            throw std::invalid_argument("Invalid conversion");
        char charValue = static_cast<char>(_stoi(s));
        if (isprint(charValue)) {
            std::cout << "char: '" << charValue << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    } catch (const std::exception&) {
        std::cout << "char: Conversion not possible" << std::endl;
    }
}

// to float
void ScalarConverter::toFloat(std::string s)
{
	try {
        double floatValue = atof(s.c_str());
        if (floatValue < std::numeric_limits<float>::min() || floatValue > std::numeric_limits<float>::max())
            throw std::invalid_argument("max");
        !(floatValue - static_cast<int>(floatValue)) ?
            std::cout << "float: " << floatValue << ".0f" << std::endl : 
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (const std::exception&) {
        std::cout << "float: Conversion not possible" << std::endl;
    }
}

// to double
void ScalarConverter::toDouble(std::string s)
{
    try {
        double doubleValue = atof(s.c_str());
        !(doubleValue - static_cast<int>(doubleValue)) ?
            std::cout << "float: " << doubleValue << ".0f" << std::endl :
        std::cout << "double: " << doubleValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "double: Conversion not possible" << std::endl;
    }
}


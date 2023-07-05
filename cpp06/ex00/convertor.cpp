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

float ScalarConverter::_stoi(std::string s)
{
    std::istringstream iss(s);
    float value;
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
        if (i == 0 && (s[0] == '+' || s[0] == '-'))
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


void ScalarConverter::convert(const std::string& literal) {

    if (literal == "nan" || literal == "-inf" || literal == "+inf" 
        || literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }
    

    if ((literal.length() == 1 && std::isprint(literal[0])) || literal[0] == 0) { 
        std::cout << "char: '" << literal << "'\n";
        std::cout << "int: " << static_cast<int>(literal[0]) << "\n";
        std::cout << "float: " << static_cast<int>(literal[0]) << "f\n";
        std::cout << "double: " << static_cast<int>(literal[0]) << "\n";
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

void ScalarConverter::toInt(std::string s)
{
    // to int
    try {
        if (s[s.length() - 1] == 'f')
            s.pop_back();
        if (_stoi(s) > INT_MAX || _stoi(s) < INT_MIN)
            throw std::invalid_argument("Invalid conversion");
        int intValue = static_cast<int>(_stoi(s));
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "int: Conversion not possible" << std::endl;
    }

}
void ScalarConverter::toChar(std::string s)
{
    // to char
    try {
        if (_stoi(s) > CHAR_MAX || _stoi(s) < CHAR_MIN)
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

void ScalarConverter::toFloat(std::string s)
{
    // to float
	try {
        if (s[s.length() - 1] == 'f')
            s.pop_back();
        float floatValue = _stoi(s);
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (const std::exception&) {
        std::cout << "float: Conversion not possible" << std::endl;
    }
}

void ScalarConverter::toDouble(std::string s)
{
    // to double
    try {
        double doubleValue = atof(s.c_str());
        std::cout << "double: " << doubleValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "double: Conversion not possible" << std::endl;
    }
}


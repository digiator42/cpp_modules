#include "BitcoinExchange.hpp"
#include <vector>

static std::vector<std::string> split(std::string str, char sep) {
    std::stringstream ss(str);
    std::string value;
    std::vector<std::string> vec;

    while (std::getline(ss, value, sep))
        if (!value.empty())
            vec.push_back(value);
    return vec;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *filePath) {
    char        buffer[1024] = {0};


    std::ifstream finput(filePath);
    if (!finput) {
		throw exception("Error: could not open : " + std::string(filePath));
    }
    this->filePath = filePath;

    std::ifstream fin("data.csv");
    if (!fin) {
		throw exception("File cannot be opened: data.csv");
    }

    if (!fin.getline(buffer, 1024))
        throw exception("Data file is empty.");

    while(fin.getline(buffer, 1024)) {
        if (std::string(buffer).find_first_not_of("0123456789-,.") != std::string::npos)
            throw exception("Wrong database.");
        std::vector<std::string> vec;
        vec = split(std::string(buffer), ',');
        if (vec.size() != 2)
            throw exception("Wrong database.");
		this->map.insert(std::make_pair(vec.at(0), std::atof(vec.at(1).c_str())));
    }
}

BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other) {
	if (this != &other) {
		this->map = other.map;
        this->filePath = other.filePath;
    }
    return *this;
}

void    BitcoinExchange::printMap(void) {

   std::map <std::string, float>::iterator it;

   for (it = this->map.begin(); it != this->map.end(); ++it) {
      std::cout << it->first << ": " << it->second << std::endl;
   }
   std::cout << "Size -->: " << map.size() << std::endl;
}

static std::string to_string(float value) {
    std::stringstream ss;
	ss << value;
	std::string s = ss.str();
	return s;
}

static bool isValidDate(const std::string& dateStr) {
    std::istringstream dateStream(dateStr);
    int year, month, day;
    char dash1, dash2;
    std::string invalid = "";

    dateStream >> year >> dash1 >> month >> dash2 >> day >> invalid;
    if (to_string(year).length() != 4)
        return false;
    if (!invalid.empty() || dash1 != '-' || dash2 != '-') {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if (month == 2 && day > 29)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    return true;
}

void    BitcoinExchange::displayData() {
    char            buffer[1024];
    std::string     dateString;
    std::string     digitString;
    std::vector<std::string> vec;
    struct          tm time;

    std::ifstream fin(this->filePath);
    if (!fin) {
        throw exception("Error: could not open : " + std::string(this->filePath));
    }
    if (!fin.getline(buffer, 1024)) 
        throw exception("Error: Input file is empty.");

    if (strcmp(buffer, "date | value") != 0)
		throw exception("Error: Invalid header: " + std::string(buffer));

    while(fin.getline(buffer, 1024))
    {
        std::string buff(buffer);
        if (buff.find("|") != std::string::npos)
            if (buff.substr(buff.find("|") + 1, buff.length() - 1).find("|") != std::string::npos) {
                std::cerr << "Error: Bad DOUBLE input: " << buff << std::endl;
                continue;
        }
        if (std::isspace(buff[0]) || std::isspace(buff[buff.length() - 1])) {
                std::cerr << "Error: Bad SPACE input: " << buff << std::endl;
                continue;
        }                
        if (buff.find("|") == std::string::npos) {
            std::cerr << "Error: Bad NO PIPE input: " << buff << std::endl;
            continue;
        }
        if (buff.find_first_not_of("0123456789-| .") != std::string::npos) {
            std::cerr << "Error: Bad input: " << buff << std::endl;
            continue;
        }

        vec = split(buffer, '|');

        if (vec.size() != 2) {
            std::cerr << "Error: Bad vector input: " << buff << std::endl;
            continue;
        }

        if (!strptime(vec.at(0).c_str(), "%Y-%m-%d", &time)) {
            std::cerr << "Error: bad date input => " << vec.at(0) <<std::endl;
            continue;
        }

        float               Digit;
        std::stringstream   ss_digit(vec.at(1));
        ss_digit >> Digit;
        int diff = buff.length() - 10 - to_string(Digit).length();

        if (Digit < 0) {
                std::cerr << "Error: negative num " << vec.at(1) << std::endl;
                continue;
        }
        if (Digit > 1000) {
                std::cerr << "Error: too large number " << vec.at(1) << std::endl;
                continue;
        }
        if (buff.length() >= 13 && buff.substr(10, diff).compare(" | ") != 0) {
            std::cerr << "Error: Bad INDENT input: " << buff << std::endl;
            continue;
        }

        if (!isValidDate(vec.at(0))) {
            std::cerr << "Error: invalid date format: " << buff << std::endl;
            continue;
        }


        std::map <std::string, float>::iterator itr;

        itr = this->map.lower_bound(vec.at(0));
        if (itr != map.begin() || itr == this->map.end())
                itr--;
        float output = (*itr).second * Digit;
        std::cout << vec.at(0).c_str() << " => " << Digit << " = " << output << std::endl;
    }
    if (!fin.getline(buffer, 1024) && !fin.eof())
        throw exception("Error: too long line.");
}

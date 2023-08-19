#include "BitcoinExchange.hpp"
#include <vector>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *filePath) {
    char        buffer[1024] = {0};

    if (strcmp(filePath, "input.txt") != 0) {
        std::cerr << "Incorrect input file" << std::endl;
        exit(1);
    }
    this->filePath = filePath;

    std::ifstream fin("data.csv");
    if (!fin) {
		throw exception("File cannot be opened: data.csv");
    }

    while(fin.getline(buffer, 1024)) {
        const char *dateDic = strtok(buffer, ",");
        const char *exchange_rate = strtok(NULL, ",");
		this->map.insert(std::make_pair(std::string(dateDic), std::atof(exchange_rate)));
    }
}

BitcoinExchange::~BitcoinExchange() {}

std::vector<std::string> split(std::string str, char sep) {
    std::stringstream ss(str);
    std::string value;
    std::vector<std::string> vec;

    while (std::getline(ss, value, sep))
        if (!value.empty())
            vec.push_back(value);
    return vec;
}

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

static bool isValidDate(const std::string& dateStr) {
    std::istringstream dateStream(dateStr);
    int year, month, day;
    char dash1, dash2;

    dateStream >> year >> dash1 >> month >> dash2 >> day;

    if (dateStream.fail() || dash1 != '-' || dash2 != '-') {
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

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

    std::fstream fin(this->filePath);
    fin.getline(buffer, 1024);

    if (strcmp(buffer, "date | value") != 0)
		throw exception("Invalid header: " + std::string(buffer));

    while(fin.getline(buffer, 1024))
    {
        std::string buff(buffer);
        if (buff.find("|") != std::string::npos)
            if (buff.substr(buff.find("|") + 1, buff.length() - 1).find("|") != std::string::npos) {
                std::cerr << "Bad DOUBLE input: " << buff << std::endl;
                continue;
        }
        if (std::isspace(buff[0]) || std::isspace(buff[buff.length() - 1])) {
                std::cerr << "Bad SPACE input: " << buff << std::endl;
                continue;
        }                
        if (buff.find("|") == std::string::npos) {
            std::cerr << "Bad NO PIPE input: " << buff << std::endl;
            continue;
        }
        else if (buff.find_first_not_of("0123456789-| ") != std::string::npos) {
            std::cerr << "Bad input: " << buff << std::endl;
            continue;
        }
        else {
            vec = split(buffer, '|');

            if (vec.size() != 2) {
                std::cerr << "Bad vector input: " << buff << std::endl;
                continue;
            }
            if (!isValidDate(vec.at(0))) {
                std::cerr << "invalid date format: " << buff << std::endl;
                continue;
            }

        }
        float               Digit;
        std::stringstream   ss_digit(vec.at(1));
        ss_digit >> Digit;

        if (!strptime(vec.at(0).c_str(), "%Y-%m-%d", &time)) {
            std::cerr << "Error: bad strptime input => " << vec.at(0) <<std::endl;
            continue;
        }
        if (std::signbit(Digit) == true) {
                std::cerr << "Error: negative num " << std::endl;
                continue;
        }
        if (Digit > 1000) {
                std::cerr << "Error: over max num " << vec.at(0) << std::endl;
                continue;
        }

        std::map <std::string, float>::iterator itr;

        itr = this->map.find(vec.at(0));
        if (itr == this->map.end()) {
            itr = this->map.lower_bound(vec.at(0));

            if (itr != map.begin())
                itr--;
        }

        float output = (*itr).second * Digit;

        std::cout << vec.at(0).c_str() << " => " << Digit << " = " << output << std::endl;
    }

}
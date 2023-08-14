#include "BitcoinExchange.hpp"

Btc::Btc() {}

Btc::Btc(char *filePath) {
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

Btc::~Btc() {}

Btc::Btc(const Btc &copy) {
    *this = copy;
}

Btc& Btc::operator=(const Btc & other) {
	if (this != &other) {
		this->map = other.map;
        this->filePath = other.filePath;
    }
    return *this;
}

void    Btc::printMap(void) {

   std::map <std::string, float>::iterator it;

   for (it = this->map.begin(); it != this->map.end(); ++it) {
      std::cout << it->first << ": " << it->second << std::endl;
   }
   std::cout << "Size -->: " << map.size() << std::endl;
}


void    Btc::displayData() {
    char            buffer[1024];
    std::string     dateString;
    std::string     digitString;
    struct          tm time;

    std::fstream fin(this->filePath);
    fin.getline(buffer, 1024);

    if (strcmp(buffer, "date | value") != 0)
		throw exception("Invalid header: " + std::string(buffer));

    while(fin.getline(buffer, 1024))
    {
        std::string buff(buffer);

        if (buff.find("|") == std::string::npos) {
            std::cout << "Bad input: " << buff << std::endl;
            continue;
        }
        else if (buff.find_first_not_of("|") == std::string::npos) {
            std::cout << "Bad input: " << buff << std::endl;
            continue;
        }
        else {
            char *Date      = strtok(buffer, "|");
            dateString      = Date;

            char *charDigit = strtok(NULL, "|");
            digitString     = charDigit;

            if (charDigit == NULL || Date == NULL) {
                std::cout << "Error: Bad Input => " << Date <<std::endl;
                continue;
            }
        }

            std::string         Date;
            float               Digit;

            std::stringstream   ss_date;
            std::stringstream   ss_digit;

            ss_date << dateString;
            ss_date >> Date;

            ss_digit << digitString;
            ss_digit >> Digit;

        if (!strptime(&Date[0], "%Y-%m-%d", &time)) {
            std::cout << "Error: bad input => " << Date <<std::endl;
            continue;
        }
        if (std::signbit(Digit) == true) {
                std::cout << "Error: negative num " << std::endl;
                continue;
        }
        if (Digit > 1000) {
                std::cout << "over max num" << std::endl;
                continue;
        }

        std::map <std::string, float>::iterator itr;

        itr = this->map.find(Date);
        if (itr == this->map.end()) {
            itr = this->map.lower_bound(Date);

            if (itr != map.begin())
                itr--;
        }

        float output = (*itr).second * Digit;

        std::cout << Date << " => " << Digit << " = " << output << std::endl;
    }

}
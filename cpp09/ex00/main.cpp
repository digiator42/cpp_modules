#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try {
        if (argc != 2) {
            throw std::invalid_argument("Error: Invalid input");
        }
        BitcoinExchange btc = BitcoinExchange(argv[1]);
        btc.displayData();
        #ifdef PRINT
        btc.printMap();
        #endif
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

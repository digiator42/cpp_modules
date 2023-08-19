#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    try {
        BitcoinExchange setup = BitcoinExchange(argv[1]);
        setup.displayData();
        // setup.printMap();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}

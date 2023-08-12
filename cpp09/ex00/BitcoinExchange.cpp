#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _rate(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		_rate = copy._rate;
	return *this;
}

void BitcoinExchange::setRate(double rate) {
	_rate = rate;
}

double BitcoinExchange::getRate() const {
	if (_rate == 0)
		throw RateNotSetException();
	return _rate;
}


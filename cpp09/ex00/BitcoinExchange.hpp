#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>

class BitcoinExchange
{
	private:
		double _rate;
		BitcoinExchange();
		
	public:	
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		void setRate(double rate);
		double getRate() const;
		class RateNotSetException : public std::exception
		{
			virtual const char *what() const throw() {
				return "Rate is not set";
			}
		};
};

#endif
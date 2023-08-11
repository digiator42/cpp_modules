#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

class Span
{
private:
	unsigned int _N;

public:
	std::vector<int> _vec;
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	Span &operator=(const Span &copy);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();

	class FullException : public std::exception
	{
		virtual const char *what() const throw() {
			return "Span is full";
		}
	};
	class NoSpanException : public std::exception
	{
		virtual const char *what() const throw() {
			return "Span is empty or has only one element";
		}
	};
};
#endif
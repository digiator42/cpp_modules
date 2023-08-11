#include "Span.hpp"


Span::Span() : _N(0) {
	_vec.reserve(_N);
}

Span::Span(unsigned int N) : _N(N) {
	_vec.reserve(_N);
}

Span::Span(const Span &copy) {
	*this = copy;
}

Span::~Span() {}

Span &Span::operator=(const Span &copy) {
	this->_N = copy._N;
	this->_vec = copy._vec;
	return *this;
}

void Span::addNumber(int n) {
	if (_vec.size() == _N)
		throw FullException();
	_vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_vec.size() + std::distance(begin, end) > _N)
		throw FullException();
	_vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan() {
	if (_vec.size() <= 1)
		throw NoSpanException();

	std::sort(_vec.begin(), _vec.end());
	int shortestDistance = _vec[1] - _vec[0];
    for (size_t i = 0; i < _vec.size() - 1; ++i) {
		// if(std::find(_vec.begin(), _vec.end(), _vec[i+1]) != _vec.end())
        	if (std::abs(_vec[i+1] - _vec[i]) < shortestDistance) {
            	shortestDistance = std::abs(_vec[i+1] - _vec[i]);
        }
    }
	return shortestDistance;
}

int Span::longestSpan() {
	if (_vec.size() <= 1)
		throw NoSpanException();
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}


#include "templates.hpp"
#include <iostream>


class Ab {
	private:
		int _n;
	public:
		Ab() : _n(0) {};
		Ab(int n) : _n(n) {};
		Ab &operator=(Ab &obj) {
			_n = obj._n;
			return *this;
		}
		bool operator>(const Ab& other) const {
        	return (this->_n > other._n);
    	}
		bool operator<(const Ab& other) const {
        	return (this->_n < other._n);
    	}

		int getN() const { return _n; };
};
std::ostream & operator<<(std::ostream & o, const Ab &a) { o << a.getN(); return o; }


int main( void ) {

	Ab a1(2);
	Ab b1(3);


	::swap( a1, b1 );
	std::cout << "min( a, b ) = " << ::min( a1, b1 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a1, b1 ) << std::endl;

	b1 = a1;
	
	::swap( a1, b1 );
	std::cout << "min( a, b ) = " << ::min( a1, b1 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a1, b1 ) << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap( c, d) ;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

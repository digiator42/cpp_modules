#include "Iter.hpp"

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

int main() {

    Ab const a[5];
    iter(a, 5, printElement);

    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::string strArray[] = {"Does", "this", "work", "?"};
    size_t strArrayLength = strArray->length();

    std::cout << "Printing strArray: \n";
    iter(strArray, strArrayLength, printElement);
    
    std::cout << "Printing intArray: \n";
    iter(intArray, intArrayLength, printElement);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Printing doubleArray: \n";
    iter(doubleArray, doubleArrayLength, printElement);

    std::string str = "TEMPLATE";
    size_t strLength = str.length();

    std::cout << "Printing doubleArray: \n";
    iter(str.c_str(), strLength, printElement);

    return 0;
}

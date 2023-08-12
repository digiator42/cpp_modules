
#include "Span.hpp"


int main()
{

	try {
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

		std::srand(time(NULL));
		std::vector<int> vec;

		for (size_t i = 0; i < 10000; i++)
		{
			int n = std::rand() % 10000;
			if (std::find(vec.begin(), vec.end(), n) == vec.end())
				vec.push_back(n);
		}
		
		#ifdef DEBUG
		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
		#endif
		
		Span sp = Span(100000);
		
		sp.addNumber(20000);
		sp.addNumber(vec.begin() + vec.size() / 2, vec.end());

		std::cout << sp.shortestSpan() << std::endl;

		#ifdef DEBUG
		for (size_t i = 0; i < sp._vec.size(); i++)
		{
			std::cout << sp._vec[i] << " ";
		}
		std::cout << std::endl;
		#endif

		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
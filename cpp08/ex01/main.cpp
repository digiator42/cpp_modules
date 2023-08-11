
#include "Span.hpp"

int main()
{

	try {
		std::srand(time(NULL));

		std::vector<int> vec;

		for (size_t i = 0; i < 1000; i++)
		{
			int n = std::rand() % 1000;
			if (std::find(vec.begin(), vec.end(), n) == vec.end())
				vec.push_back(n);
		}
		
		
		Span sp = Span(1000000);
		
		sp.addNumber(vec.begin(), vec.end());

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
#include "PmergeMe.hpp"

template<typename Container>
static void printCont(Container &con) {
    typename Container::iterator itr; 
    for (itr = con.begin(); itr != con.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

static void timeElapsed(std::clock_t start, int count, bool vec) { 

    double duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << count << " elements " << 
        (!vec ? "with std::list<unsigned int> : " :  "with std::vector<unsigned int> :")
        << duration << " us" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	    return EXIT_SUCCESS;

    PmergeMe pmm;
    std::vector<unsigned int> vec;
    std::string arg;

    try {
        for (int i = 1; i < argc; i++)
        {
            std::istringstream ss(argv[i]);
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw std::invalid_argument("Invalid input");
            if (!(ss >> arg))
			    throw std::invalid_argument("Invalid input");
            vec.push_back(std::atoi(arg.c_str()));
            while(ss >> arg)
                vec.push_back(std::atoi(arg.c_str()));
        }
        std::cout << "Before: ";
        printCont(vec);

        std::vector<unsigned int> uVector(vec.begin(), vec.end());
        std::list<unsigned int> unSortedList(vec.begin(), vec.end());

        std::clock_t start = std::clock();
        std::vector<unsigned int> sortedVec =  pmm.mergeVec(uVector);
        std::cout << "After:  ";
        printCont(sortedVec);
        timeElapsed(start, argc-1, true);

        start = std::clock();

        std::list<unsigned int> sortedList =  pmm.mergeVec(unSortedList);
        timeElapsed(start, argc-1, false);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}

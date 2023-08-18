#include "PmergeMe.hpp"

template<typename Container>
static void printCont(Container &con) {
    typename Container::iterator itr; 
    for (itr = con.begin(); itr != con.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
static bool isSorted(Container &con) {
    typename Container::iterator itr;
    typename Container::iterator itr2;
    for (itr = con.begin(); itr != con.end(); ++itr)
    {
        for (itr2 = std::next(itr); itr2 != con.end(); itr2++) // not in cpp 98
            if (*itr > *itr2)
		        return false;
    }
    return true;
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
        for (int i = 1; i < argc; i += 1)
        {
            std::istringstream ss(argv[i]);
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw std::invalid_argument("Invalid input");
            if (!(ss >> arg))
			    throw std::invalid_argument("Invalid input");
        }
        for (int i = 1; i < argc; i += 1)
            vec.push_back(std::atoi(argv[i]));
        // printCont(vec);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    std::vector<unsigned int> uVector(vec.begin(), vec.end());
    std::list<unsigned int> notSortedList(vec.begin(), vec.end());

    std::clock_t start = std::clock();
    std::vector<unsigned int> sortedVec =  pmm.mergeVec(uVector);
    timeElapsed(start, argc-1, true);
    std::cout <<  std::endl;
    // printCont(sortedVec);

    std::cout << "\n--------\n";

    start = std::clock();

    std::list<unsigned int> sortedList =  pmm.mergeVec(notSortedList);
    timeElapsed(start, argc-1, false);
    // printCont(sortedList);
    std::cout <<  std::endl;
    std::cout << "vec " << (isSorted(sortedVec) ? "YES" : "NO") << std::endl;
    std::cout << "list " << (isSorted(sortedList) ? "YES" : "NO") << std::endl;

	return EXIT_SUCCESS;
}

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
        for (itr2 = std::next(itr); itr2 != con.end(); itr2++)
            if (*itr >= *itr2)
		        return false;
    }
    return true;
}



int main(int argc, char **argv)
{
	if (argc == 1)
	    return EXIT_SUCCESS;
    PmergeMe pmm;
    std::vector<unsigned int> vec;
    try {
        for (int i = 1; i < argc; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw std::invalid_argument("Invalid input");

        for (int i = 1; i < argc; i += 1)
            vec.push_back(std::atoi(argv[i]));
        printCont(vec);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    std::vector<unsigned int> uVector(vec.begin(), vec.end());
    std::list<unsigned int> notSortedList(vec.begin(), vec.end());

    std::vector<unsigned int> sortedVec =  pmm.mergeVec(uVector);
    std::cout <<  std::endl;
    printCont(sortedVec);

    std::cout << "\n--------\n";


    std::list<unsigned int> sortedList =  pmm.mergeVec(notSortedList);
    printCont(sortedList);
    std::cout <<  std::endl;
    std::cout << "vec " << (isSorted(sortedVec) ? "YES" : "NO") << std::endl;
    std::cout << "list " << (isSorted(sortedList) ? "YES" : "NO") << std::endl;

	return EXIT_SUCCESS;
}

#include "PmergeMe.hpp"


template<typename Container>
static void printCont(Container &con) {
    typename Container::iterator itr; 
    for (itr = con.begin(); itr != con.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

static bool isSorted(std::vector<unsigned int> vec) {
        std::vector<unsigned int>::iterator itr;
        std::vector<unsigned int>::iterator itr2;
        for (itr = vec.begin(); itr != vec.end(); ++itr)
        {
            for (itr2 = itr + 1; itr2 != vec.end(); itr2++)
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
    std::set<unsigned int> uSet;
    try {
        for (int i = 1; i < argc; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw std::invalid_argument("Invalid input");

        for (int i = 1; i < argc; i += 1)
            uSet.insert(std::atoi(argv[i]));
        // printVec(pmm.vec);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    std::vector<unsigned int> uVector(uSet.begin(), uSet.end());
    std::vector<unsigned int> vec =  pmm.mergeVec(uVector);
    printCont(vec);
    std::cout << "\n--------\n";

    std::set<unsigned int> rset =  pmm.mergeVec(uSet);
    printCont(rset);
    std::cout <<  std::endl;
    std::cout << (isSorted(vec) ? "YES" : "NO") << std::endl;

	return EXIT_SUCCESS;
}

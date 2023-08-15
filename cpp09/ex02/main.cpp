#include "PmergeMe.hpp"


static void printVec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int>::const_iterator itr; //const is not in cpp98
	for (itr = vec.begin(); itr != vec.end(); itr++)
		 std::cout << *itr << " ";
	 std::cout <<  std::endl;
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

    try {
        for (int i = 1; i < argc; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw std::invalid_argument("Invalid input");

        for (int i = 1; i < argc; i += 1)
            pmm.vec.push_back(std::atoi(argv[i]));

        std::vector<unsigned int>::iterator itr;
        std::vector<unsigned int>::iterator itr2;
        for (itr = pmm.vec.begin(); itr != pmm.vec.end(); ++itr)
        {
            for (itr2 = itr + 1; itr2 != pmm.vec.end(); itr2++)
                if (*itr == *itr2)
			        throw std::invalid_argument("Duplicate numbers");
        }
        // printVec(pmm.vec);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    std::vector<unsigned int> vec =  pmm.mergeVec(pmm.vec);
    std::cout << "\n--------\n";
    printVec(vec);
    std::cout <<  std::endl;
    std::cout << (isSorted(vec) ? "YES" : "NO") << std::endl;

	return EXIT_SUCCESS;
}

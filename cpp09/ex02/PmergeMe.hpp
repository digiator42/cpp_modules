#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <ctime>


class PmergeMe {
    public:
    	std::vector<unsigned int> vec;
        PmergeMe(void);
        PmergeMe(const PmergeMe& to_copy);
        PmergeMe &operator=(const PmergeMe& to_copy);
        ~PmergeMe(void);

        std::vector<unsigned int> mergeVec(std::vector<unsigned int>& vec);
        std::list<unsigned int> mergeVec(std::list<unsigned int>& list);
};

#endif
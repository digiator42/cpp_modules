#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <set>



class PmergeMe {
    public:
    	std::vector<unsigned int> vec;
        PmergeMe(void);
        PmergeMe(const PmergeMe& to_copy);
        PmergeMe &operator=(const PmergeMe& to_copy);
        ~PmergeMe(void);

        std::vector<unsigned int> mergeVec(std::vector<unsigned int>& vec);
        std::set<unsigned int> mergeVec(std::set<unsigned int>& set);

};

#endif
#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>


PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe& to_copy) {
    *this = to_copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	(void)to_copy;
	return *this;
}

PmergeMe::~PmergeMe(void) {};

static std::vector<unsigned int> sortVec(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
    std::vector<unsigned int> result;

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
            continue;
        }
        result.push_back(right.front());
        right.erase(right.begin());
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}


static std::list<unsigned int> sortSet(std::list<unsigned int>& left, std::list<unsigned int>& right) {
    
    std::list<unsigned int> result;

    while (!left.empty() && !right.empty()) {
        if (*left.begin() <= *right.begin()) {
            result.push_back(*left.begin());
            left.erase(left.begin());
            continue;
        }
        result.push_back(*right.begin());
        right.erase(right.begin());
    }

    while (!left.empty()) {
        result.push_back(*left.begin());
        left.erase(left.begin());
    }

    while (!right.empty()) {
        result.push_back(*right.begin());
        right.erase(right.begin());
    }

    return result;
}

std::vector<unsigned int> PmergeMe::mergeVec(std::vector<unsigned int>& vec) {

    if (vec.size() <= 1) {
        return vec;
    }

    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    left = mergeVec(left);
    right = mergeVec(right);

    return sortVec(left, right);
}

std::list<unsigned int> PmergeMe::mergeVec(std::list<unsigned int>& list) {

    if (list.size() <= 1) {
        return list;
    }

    int mid = list.size() / 2;
    std::list<unsigned int>::iterator lit = list.begin();

    std::list<unsigned int> left;
    std::list<unsigned int> right;

    for (int i = 0; i < mid; i++)
        left.push_back(*lit++);
    for (int i = mid; i < (int)list.size(); i++)
        right.push_back(*lit++);
    
    left = mergeVec(left);
    right = mergeVec(right);

    return sortSet(left, right);
}

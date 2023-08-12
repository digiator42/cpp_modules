#include "MutantStack.hpp"
#include <list>

int main () {

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator itl = mstack.begin();
    MutantStack<int>::iterator itel = mstack.end();
    ++itl;
    --itl;
    std::cout << "stack: ";
    while (itl != itel) {
        std::cout << *itl << " ";
        ++itl;
    }
    std::cout << std::endl;
    while (!mstack.empty()) {
        std::cout << mstack.top() <<" "; 
        mstack.pop();
    }
    std::cout << "\n----------list-----------" << std::endl;
    
    std::list<int> lit;
    lit.push_back(5);
    lit.push_back(17);
    std::cout << "top: " << lit.front() << std::endl;
    lit.remove(17);
    std::cout << "size: " << lit.size() << std::endl;
    lit.push_back(3);
    lit.push_back(5);
    lit.push_back(737);
    lit.push_back(0);
    std::list<int>::iterator itb = lit.begin();
    std::list<int>::iterator ite = lit.end();
    ++itb;
    --itb;
    std::cout << "stack: ";
    while (itb != ite) {
        std::cout << *itb << " ";
        ++itb;
    }
    std::cout << std::endl;
    
    return 0;
}

#include "MutantStack.hpp"

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
    MutantStack<int>::iterator itb = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
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
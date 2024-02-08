#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
//-------- Orthodox Canonical Form ---------
    MutantStack() {};
    MutantStack(const MutantStack& orig) {*this = orig;};
    MutantStack& operator=(const MutantStack& orig) {(void)orig; return *this;};
    ~MutantStack() {};
//---------------- attributes ----------------
    typedef typename std::stack<T>::container_type::iterator iterator;
//---------------- methods ----------------
    iterator begin() {return this->c.begin();}; //c - container, begin()- stack member function
    iterator end() {return this->c.end();}; //c - container, end()- stack member function
};

#endif
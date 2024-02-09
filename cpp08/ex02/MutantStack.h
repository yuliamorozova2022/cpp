#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <stack>
// #include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
//-------- Orthodox Canonical Form ---------
	MutantStack() {};
	MutantStack(const MutantStack& orig) : std::stack<T>(orig) {};
	MutantStack& operator=(const MutantStack& orig) {
		if (*this == orig) 
			return *this;
		this->c = orig.c;
		return *this;
	};
	~MutantStack() {/* this->c.clear(); */};
//---------------- attributes ----------------
	typedef typename std::stack<T>::container_type::iterator iterator;
//---------------- methods ----------------
	iterator begin() {return this->c.begin();}; //c - container, begin()- stack member function
	iterator end() {return this->c.end();}; //c - container, end()- stack member function

};

#endif
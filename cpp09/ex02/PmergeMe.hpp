#ifndef __PMERGEME__
#define __PMERGEME__

// #include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class PmergeMe {
public:
    PmergeMe(int ac, char* av[]);
//-------- Orthodox Canonical Form ---------
    PmergeMe();
    PmergeMe(const PmergeMe& orig);
    PmergeMe& operator = (const PmergeMe& orig);
    ~PmergeMe();
//---------------- methods ----------------
    void sort();
private:
    std::vector<int> _vect;
    std::list<int> _list;
    std::deque<int> _deq;
};

#endif
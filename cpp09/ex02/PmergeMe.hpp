#ifndef __PMERGEME__
#define __PMERGEME__

// #include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

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
    // std::deque<int> _deq;
};
//---------------- templates ----------------
#define Iter typename Container::iterator

template <class InputIt>
void printCont(InputIt start, InputIt end) {
	if (start == end) {
		std::cout << "Empty!";
	} else {
		int i = 0;
		while (start != end) {
			if (i == 5) {
				std::cout << "[ ... ]";
				break;
			}
			std::cout << *start << " ";
			++start; 
			i++;
		}
	}
	std::cout << std::endl;
}

template <typename Container>
Container mergeCont(Container& container1, Container& container2) {
	Container res;
	Iter it1 = container1.begin();
	Iter it2 = container2.begin();
	while (it1 != container1.end() && it2 != container2.end()) {
		if (*it1 <= *it2) {
			res.push_back(*it1);
			it1++;
		} else {
			res.push_back(*it2);
			it2++;
		}
	}
	res.insert(res.end(), it1, container1.end());
	res.insert(res.end(), it2, container2.end());
	return res;
}
/*
	template< class InputIt, class Distance >
	void advance( InputIt& it, Distance n );
	Increments given iterator it by n elements. If n is negative, the iterator is decremented. In this case, InputIt must meet the requirements of LegacyBidirectionalIterator, otherwise the behavior is undefined.
*/
template <typename Container>
Container sortCont(Container& container) {
	if (container.size() <= 1) {
		return container;
	}
	Container first_cont, second_cont;
	Iter mid = container.begin();
	std::advance(mid, container.size()/2); //see comment above
	first_cont.assign(container.begin(), mid); // copy container: "conteiner where to copy".assign("pointer to elem from", "pointer to element to")
	second_cont.assign(mid, container.end());
    // std::cout << "First: ";
    // printCont(first_cont.begin(), first_cont.end());
    // std::cout << "Second: ";
    // printCont(second_cont.begin(), second_cont.end());
	first_cont = sortCont(first_cont);
	second_cont = sortCont(second_cont);
	return mergeCont(first_cont, second_cont);
}

#endif
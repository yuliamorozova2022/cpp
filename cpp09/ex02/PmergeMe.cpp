#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe(int ac, char *av[]) {
	std::string str;
	long tmp;
	for (int i = 1; i < ac; i++) {
		str = av[i];
		// std::cout << "str is <" << str << ">\n";
		for (int j = 0; str[j]; j++) {
			if (std::isdigit(str[j]) == false) {
				if (str[j] == '-' || str[j] == '+')
					continue;
				throw std::invalid_argument(RED "Error: received non numeric value" NRM);
			}
		}
		tmp = std::atol(str.c_str());
		if (tmp < 0) {
			throw std::invalid_argument(RED "Error: received negative value" NRM);
		}
		if (tmp > INT_MAX) {
			throw std::invalid_argument(RED "Error: received value bigger than integer max (2147483647)" NRM);
		}
		_vect.push_back(static_cast<int>(tmp));
		_list.push_back(static_cast<int>(tmp));
		// _deq.push_back(static_cast<int>(tmp));
	}
}
//-------- Orthodox Canonical Form ---------
PmergeMe::PmergeMe() {
}
PmergeMe::PmergeMe(const PmergeMe& orig) {
	*this = orig;
}
PmergeMe& PmergeMe::operator = (const PmergeMe& orig) {
	if (this == &orig) {
		return *this;
	}
	//one has to be removed!!
	_vect = orig._vect;
	_list = orig._list;
	// _deq = orig._deq;
	return *this;
}
PmergeMe::~PmergeMe() {
}

//---------------- methods ----------------
void PmergeMe::sort() {
	clock_t time_start1, time_start2/*, time_start3*/;
	clock_t time_end1, time_end2/*, time_end3*/;
	std::cout << "Before: ";
	// std::cout << "Vector is: " /*<< std::endl*/;
	printCont(_vect.begin(), _vect.end());

	time_start1 = clock();
	std::vector<int> res1 = sortCont<std::vector<int> >(_vect);
	time_end1 = clock();

	std::cout << "After: ";
	printCont(res1.begin(), res1.end());
	// std::cout << "\nList is: " /*<< std::endl*/;
	// printCont(_list.begin(), _list.end());
	time_start2 = clock();
	std::list<int> res2 = sortCont<std::list<int> >(_list);
	time_end2 = clock();
	// // std::list<int> res2 = sortCont<std::list<int> >(_list);
	// printCont(res2.begin(), res2.end());
	// std::cout << "\nDeque is: " /*<< std::endl*/;
	// printCont(_deq.begin(), _deq.end());
	// time_start3 = clock();
	// std::deque<int> res3 = sortCont<std::deque<int> >(_deq);
	// time_end3 = clock();
	// printCont(res3.begin(), res3.end());

	std::cout << "Time to process a range of	"<<_vect.size()<<" elements with std::vector : " << 1000 * ((double)(time_end1 - time_start1) / CLOCKS_PER_SEC) <<" ms" << std::endl;
	std::cout << "Time to process a range of	"<<_list.size()<<" elements with std::list : " << 1000 * ((double)(time_end2 - time_start2) / CLOCKS_PER_SEC) <<" ms" << std::endl;
	// std::cout << "Time to process a range of	"<<_deq.size()<<" elements with std::deque : " << 1000 * ((double)(time_end3 - time_start3) / CLOCKS_PER_SEC) <<" ms" << std::endl;

}





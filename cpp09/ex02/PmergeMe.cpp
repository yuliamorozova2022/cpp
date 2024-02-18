#include "PmergeMe.hpp"
#include <ctime>

// #define Iter typename Container::iterator

template <class InputIt>
void printCont(InputIt start, InputIt end, size_t size) {
	std::cout << "[";
	if (start == end) {
		std::cout << "Empty!";
	} else {
		int i = 0;

		while (start != end) {
			std::cout << *start << " ";
			++start; 
		}
	}
	std::cout << "]"<< std::endl;
}
/*
template <class InputIt>
void changeIters(InputIt &a, InputIt &b, char sign) {
	if (sign == '+') {
		a++;
		b++;
	} else {
		a--;
		b--;
	}
}

template <typename Container>
Container sortCont(const Container& container) {
	// using ElementType = typename Container::value_type;
	// ElementType v;
	Container a, b;
	// std::cout << "heloooooooooooooo\n";
	typename Container::const_iterator is = container.begin();
	typename Container::const_iterator ie = container.end();
	while (is != ie) {
		b.push_back(*is);
		is++;
		if (is == ie) {
			a.push_back(-1);
			break;
		} else {
			a.push_back(*is);
		}
		is++;
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	Iter ibs = b.begin();
	Iter ias = a.begin();
	for ( ; ibs != b.end(); ibs++, ias++) {
		// std::cout << "*ias = " << *ias << ", *ibs = " <<*ibs<<std::endl;
		if (*ias > *ibs) {
			int tmp = *ias;
			*ias = *ibs;
			*ibs = tmp;
			// std::cout << "swap" << std::endl;
		}
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	ibs = b.begin();
	ias = a.begin();
	// std::cout << "ias = "<<std::distance(a.begin(), ias) << ", ibs = "<<std::distance(b.begin(), ibs)<<std::endl;
	ibs++;
	ias++;
	// std::cout << "ias++ = "<<std::distance(a.begin(), ias) << ", ibs++ = "<<std::distance(b.begin(), ibs)<<std::endl;
		
	for ( ; ibs != b.end(); ibs++, ias++) {
		Iter tmpb1 = ibs;
		Iter tmpb0 = ibs;
		Iter tmpa1 = ias;
		Iter tmpa0 = ias;
		changeIters(tmpb0, tmpa0, '-');
		// std::cout << "tmpb0 = "<<std::distance(b.begin(), tmpb0) << ", tmpa0 = "<<std::distance(a.begin(), tmpa0)<<std::endl;
		// std::cout << "tmpb1 = "<<std::distance(b.begin(), tmpb1) << ", tmpa1 = "<<std::distance(a.begin(), tmpa1)<<std::endl;
	
		while (tmpb1 != b.end() && *tmpb0 > *tmpb1) {
			std::swap(*tmpb0, *tmpb1);
			std::swap(*tmpa0, *tmpa1);
			changeIters(tmpb0, tmpb1, '-');
			changeIters(tmpa0, tmpa1, '-');
		}
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	Container res(b);
	ias = a.begin();
	ibs = b.begin();
	if (*ias != -1) {
		res.insert(res.begin(), *ias); //because we know that in a elements are less than in b
	}
	std::cout << "res container:" << std::endl;
	printCont(res.begin(), res.end());
	changeIters(ias, ibs, '+');
	// std::cout << "ias = "<<std::distance(a.begin(), ias) << ", ibs = "<<std::distance(b.begin(), ibs)<<std::endl;
	
		std::cout << "for loop:\n" << std::endl;
	for ( ; ias != a.end(); ias++, ibs++){
			std::cout << "______________________" << std::endl;
			std::cout << "res: ";
			printCont(res.begin(), res.end());
			std::cout << "b: ";
			printCont(b.begin(), b.end());
			std::cout << "a: ";
			printCont(a.begin(), a.end());
		if (*ias == -1) {
			continue;
		}
			std::cout << "ias = "<<std::distance(a.begin(), ias) << ", ibs = "<<std::distance(b.begin(), ibs)<<std::endl;
			std::cout << "*ias = "<<*ias << ", *ibs = "<<*ibs<<std::endl;
	
		Iter iter1 = std::find(res.begin(), res.end(), *ibs);
		Iter iter0 = std::find(res.begin(), res.end(), *ibs);
		iter0--;
			std::cout << "iter0 = "<<std::distance(res.begin(), iter0) << ", iter1 = "<<std::distance(res.begin(), iter1)<<", *iter1 = "<< *iter1<<std::endl;
	
		while (iter1 != res.begin() && *ias < *(iter1)) {
				std::cout << "*ias = "<<*ias << ", *iter1 = "<<*iter1<<std::endl;
	
			iter1--;
		}
		res.insert(++iter1, *ias);
		printCont(res.begin(), res.end());
	}
	return res;
}*/
 /*
template <typename Container>
Container sortCont(const Container& container) {
	#define CIter typename Container::const_iterator;
	// using ElementType = typename Container::value_type;
	// ElementType v;
	Container a, b;
	// std::cout << "heloooooooooooooo\n";
	CIter is = container.begin();
	CIter ie = container.end();
	while (is != ie) {
		b.push_back(*is);
		is++;
		if (is == ie) {
			a.push_back(-1);
			break;
		} else {
			a.push_back(*is);
		}
		is++;
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	for (size_t i = 0; i < b.size(); i++) {
		if (a[i] > b[i]) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	for (size_t i = 1; i < b.size(); i++) {
		std::size_t tmp1 = i;
		std::size_t tmp0 = i - 1;
		while (tmp1 != 0 && b[tmp0] > b[tmp1]) {
			std::swap(b[tmp0], b[tmp1]);
			std::swap(a[tmp0], a[tmp1]);
			tmp0--;
			tmp1--;
		}
	}
	printCont(b.begin(), b.end());
	printCont(a.begin(), a.end());
	Container res(b);
	if (a[0] != -1) {
		res.insert(res.begin(), a[0]);
	}
	printCont(res.begin(), res.end());
	for (size_t i = 1; i < a.size(); i++){
		if (a[i] == -1) {
			continue;
		}
		CIter iter = std::find(res.begin(), res.end(), b[i]);
		while (iter != res.begin() && a[i] < *(iter - 1)) {
			iter--;
		}
		res.insert(iter, a[i]);
		printCont(res.begin(), res.end());
	}
	return res;
}*/
/*
std::vector<int> sortVect(std::vector<int> &container) {
	std::vector<int> a, b;
	for (std::vector<int>::iterator is = container.begin(); is < container.end(); is++) {
		b.push_back(*is);
		is++;
		if (is == container.end()) {
			a.push_back(-1);
			break;
		} else {
			a.push_back(*is);
		}
	}
	std::cout << "b: ";
	printCont(b.begin(), b.end());
	std::cout << "a: ";
	printCont(a.begin(), a.end());
	std::cout << "----------------------" << std::endl;
	for (size_t i = 0; i < b.size(); i++) {
		if (a[i] > b[i]) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}
	std::cout << "b: ";
	printCont(b.begin(), b.end());
	std::cout << "a: ";
	printCont(a.begin(), a.end());
	std::cout << "----------------------" << std::endl;
	for (size_t i = 1; i < b.size(); i++) {
		std::size_t tmp1 = i;
		std::size_t tmp0 = i - 1;
			std::cout << "for loop: tmp0 = "<<tmp0<<" tmp1 = "<<tmp1<<std::endl;
		while (tmp1 != 0 && b[tmp0] > b[tmp1]) {
			std::cout << "***************" << std::endl;
			std::swap(b[tmp0], b[tmp1]);
			std::swap(a[tmp0], a[tmp1]);
			tmp0--;
			tmp1--;
			std::cout << "while loop: tmp0 = "<<tmp0<<" tmp1 = "<<tmp1<<std::endl;
			std::cout << "b: ";
			printCont(b.begin(), b.end());
			std::cout << "a: ";
			printCont(a.begin(), a.end());
		}
	}
	std::cout << "***************" << std::endl;
	std::cout << "b: ";
	printCont(b.begin(), b.end());
	std::cout << "a: ";
	printCont(a.begin(), a.end());
	std::cout << "----------------------" << std::endl;
	std::vector<int> res(b);
	if (a[0] != -1) {
		res.insert(res.begin(), a[0]);
	}
	std::cout << "***************" << std::endl;
	std::cout << "res: ";
	printCont(res.begin(), res.end());
	std::cout << "_____________" << std::endl;
	for (size_t i = 1; i < a.size(); i++){
		if (a[i] == -1) {
			continue;
		}
		std::vector<int>::iterator iter = std::find(res.begin(), res.end(), b[i]);
		std::cout <<"a["<< i<< "]="<<a[i]<<", b["<<i<<"]="<<b[i]<<", iter = "<< std::distance(res.begin(), iter)<<std::endl;
		while (iter != res.begin() && a[i] < *(iter - 1)) {
			iter--;
		}
		std::cout <<" iter = "<< std::distance(res.begin(), iter)<<std::endl;
		
		res.insert(iter, a[i]);
		std::cout << "res: ";
		printCont(res.begin(), res.end());
		std::cout << "***************" << std::endl;
	}
	return res;
}

std::deque<int> sortDeq(std::deque<int> &container) {
	std::deque<int> a;
	std::deque<int> b;
	for (std::deque<int>::iterator it = container.begin(); it != container.end(); it++) {
		b.push_back(*it);
		it++;
		if (it == container.end()) {
			a.push_back(-1);
			break;
		} else
			a.push_back(*it);
	}
	for (std::size_t i = 0; i < b.size(); i++) {
		if (a[i] > b[i]) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}
	for (std::size_t i = 1; i < b.size(); i++) {
		std::size_t tmp = i;
		std::size_t temp2 = i - 1;
		while (tmp != 0 && b[tmp] < b[temp2]) {
			std::swap(b[tmp], b[temp2]);
			std::swap(a[tmp], a[temp2]);
			--tmp;
			--temp2;
		}
	}
	std::deque<int> sorted(b);
	if (a[0] != -1)
		sorted.insert(sorted.begin(), a[0]);
	for (std::size_t i = 1; i < a.size(); i++) {
		if (a[i] == -1)
			continue;
		std::deque<int>::iterator it = std::find(sorted.begin(), sorted.end(), b[i]);
		while (it != sorted.begin() && a[i] < *(it - 1))
			it--;
		sorted.insert(it, a[i]);
	}
	return sorted;
}

std::list<int> sortDeq(std::list<int> &container) {
	std::list<int> a;
	std::list<int> b;
	for (std::list<int>::iterator it = container.begin(); it != container.end(); it++) {
		b.push_back(*it);
		it++;
		if (it == container.end()) {
			a.push_back(-1);
			break;
		} else
			a.push_back(*it);
	}
	for (std::size_t i = 0; i < b.size(); i++) {
		if (a[i] > b[i]) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}
	for (std::size_t i = 1; i < b.size(); i++) {
		std::size_t tmp = i;
		std::size_t temp2 = i - 1;
		while (tmp != 0 && b[tmp] < b[temp2]) {
			std::swap(b[tmp], b[temp2]);
			std::swap(a[tmp], a[temp2]);
			--tmp;
			--temp2;
		}
	}
	std::list<int> sorted(b);
	if (a[0] != -1)
		sorted.insert(sorted.begin(), a[0]);
	for (std::size_t i = 1; i < a.size(); i++) {
		if (a[i] == -1)
			continue;
		std::list<int>::iterator it = std::find(sorted.begin(), sorted.end(), b[i]);
		while (it != sorted.begin() && a[i] < *(it - 1))
			it--;
		sorted.insert(it, a[i]);
	}
	return sorted;
}
*/

PmergeMe::PmergeMe(int ac, char *av[]) {
	std::string str;
	long tmp;
	for (int i = 1; i < ac; i++) {
		str = av[i];
		// std::cout << "str is <" << str << ">\n";
		for (int j = 0; str[j]; j++) {
		// 	if (str[i] == '+' || str[i] == '-') {
		// 		continue;
		// 	}
			if (std::isdigit(str[j]) == false) {
				if (std::isdigit(str[j]) != '-' || std::isdigit(str[j]) != '+')
					continue;
				throw std::invalid_argument("Error: received non numeric value");
			}
		}
		tmp = std::atol(str.c_str());
		// std::cout << "tmp = " <<tmp << "\n";
		if (tmp < 0) {
			throw std::invalid_argument("Error: received negative value");
		}
		if (tmp > INT_MAX) {
			throw std::invalid_argument("Error: received value bigger than integer max (2147483647)");
		}
		_vect.push_back(static_cast<int>(tmp));
		_list.push_back(static_cast<int>(tmp));
		_deq.push_back(static_cast<int>(tmp));
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
	_deq = orig._deq;
	return *this;
}
PmergeMe::~PmergeMe() {
}

//---------------- methods ----------------
void PmergeMe::sort() {
	clock_t time_start;
	std::cout << "Vector is: " /*<< std::endl*/;
	printCont(_vect.begin(), _vect.end());
	// std::vector<int> res1 = sortCont<std::vector<int> >(_vect);
	// std::vector<int> res1 = sortVect(_vect);

	// std::vector<int> res1 = sortV(_vect);
	// for (std::vector<int>::iterator i = _vect.begin(); i != _vect.end(); i++) {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;
	// printCont(res1.begin(), res1.end());
	std::cout << "\nList is: " /*<< std::endl*/;
	printCont(_list.begin(), _list.end());
	// std::list<int> res2 = sortCont<std::list<int> >(_list);
	// // std::list<int> res2 = sortCont<std::list<int> >(_list);
	// printCont(res2.begin(), res2.end());
	// for (std::list<int>::iterator i = _list.begin(); i != _list.end(); i++) {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;
	std::cout << "\nDeque is: " /*<< std::endl*/;
	// for (std::deque<int>::iterator i = _deq.begin(); i != _deq.end(); i++) {
	// 	std::cout << *i << " ";
	// }
	printCont(_deq.begin(), _deq.end());
	// std::deque<int> res3 = sortDeq(_deq);
	// std::deque<int> res3 = sortCont<std::deque<int> >(_deq);
	// printCont(res3.begin(), res3.end());
	// std::cout << std::endl;
}





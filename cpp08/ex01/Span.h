#ifndef __SPAN__
#define __SPAN__

#include <iostream>
#include <exception>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>


class Span {
public:
    Span(unsigned int size);
//-------- Orthodox Canonical Form ---------
	Span();
	Span(const Span& orig);
	/*virtual*/ ~Span();
	Span& operator = (const Span& orig);
//---------------- methods ------------------
	void addNumber(int n);
    void addRange(int start, int end);
    // int shortestSpan();
    // int longestSpan();
    void print();

private:
    std::vector<int> _vect;
    unsigned int _size;

    class StorageFullException : public std::exception {
		const char* what() const throw();
	};
    class InvalidRangeException : public std::exception {
		const char* what() const throw();
	};
    class NotEnoughSpaceException : public std::exception {
		const char* what() const throw();
	};
};

#endif
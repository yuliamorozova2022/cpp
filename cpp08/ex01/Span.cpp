#include "Span.h"

Span::Span(unsigned int size) {
	_size = size;
	_vect.reserve(_size);
	std::cout << "Size constructor" << std::endl;
}

//-------- Orthodox Canonical Form ---------
Span::Span() {
	_size = 0;
	_vect.reserve(_size);
	std::cout << "Default constructor" << std::endl;
}
Span::Span(const Span& orig) {
	_size = orig._size;
	_vect = orig._vect;
	std::cout << "Copy construtor" << std::endl;
}
Span::~Span() {
	std::cout << "Destructor" << std::endl;
}
Span& Span::operator = (const Span& orig) {
	std::cout << "Assignment operator" << std::endl;
	if (this == &orig) {
		return *this;
	}
	_size = orig._size;
	_vect = orig._vect;
	return *this;
}

//---------------- methods ------------------
void Span::addNumber(int n) {
	if (_size == _vect.size()) {
		throw StorageFullException();
	}
	_vect.push_back(n);
}
void Span::addRange(int start, int end) {
	if (_size == _vect.size()) {
		throw StorageFullException();
	}
	if (start >= end) {
		throw InvalidRangeException();
	}
	if (end - start > static_cast<int>(_size - _vect.size())) {
		throw NotEnoughSpaceException();
	}
	std::vector<int> v;
	for (int i = start; i < end; i++) {
		v.push_back(i);
	}
	_vect.insert(_vect.end(), v.begin(), v.end());
}

// int shortestSpan() {

// }
// int longestSpan() {

// }
//for debugging
void Span::print() {
	if (_vect.size() == 0) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for (int i = 0; i < static_cast<int>(_vect.size()); i++) {
		std::cout << _vect[i] << " ";
	}
	std::cout << std::endl;
}

//---------------- exceptions ----------------
const char* Span::StorageFullException::what() const throw() {
	return ("	Storage is full! Not possible to add new int.\n");
}
const char* Span::InvalidRangeException::what() const throw() {
	return ("	Wrong range!\n");
}
const char* Span::NotEnoughSpaceException::what() const throw() {
	return ("	Not enough space in storage to add all these numbers!\n");
}
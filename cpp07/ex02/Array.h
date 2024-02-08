#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <exception>
#define RED "\033[0;91m"
#define NRM "\033[0;39m"

template <typename T>
class Array {
public:
    Array(unsigned int size);
//-------- Orthodox Canonical Form ---------
    Array();
    Array(const Array &orig);
    Array& operator=(const Array &orig);
    ~Array();
//---------------- [] operator overload -----------------  
    T &operator[](int index) const;
//---------------- getters -----------------
    unsigned int size() const;
//---------------- exceptions ---------------
    class OutOfBoundsException : public std::exception {
		const char* what() const throw();
	};
//---------------- attributes ----------------
private:
    unsigned int _size;
    T* _ptr;
};

#include "Array.tpp"

#endif
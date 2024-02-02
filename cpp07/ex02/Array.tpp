#include "Array.h"

template <typename T> Array<T>::Array(unsigned int size) { 
    _size = size;
    _ptr = new T[size];
}
//-------- Orthodox Canonical Form ---------
template <typename T> Array<T>::Array() { 
    _size = 0;
    _ptr = NULL;
}

template <typename T> Array<T>::Array(const Array &orig) {
    _size = orig.size();
    _ptr = new T [_size];
    for (size_t i = 0; i < _size; i++) {
        _ptr[i] = orig[i];
    }
}

template <typename T> Array<T>& Array<T>::operator=(const Array &orig) {
    if (*this == orig) {
        return *this;
    }
    _size = orig.size();
    _ptr = new T [_size];
    for (size_t i = 0; i < _size; i++) {
        _ptr[i] = orig[i];
    }
    return *this;
}

template <typename T> Array<T>::~Array() {
    delete[] _ptr;
    _ptr = NULL;
}
//---------------- getters -----------------
template <typename T> unsigned int Array<T>::size() const {
    return _size;
}
//---------------- [] operator overload -----------------
template <typename T> T& Array<T>::operator[](int idx) const{
    if (idx < 0 || idx >= static_cast<int>(_size)) {
        throw OutOfBoundsException();
    } else {
        return _ptr[idx];
    }
}

//---------------- exceptions ----------------
template <typename T> const char* Array<T>::OutOfBoundsException::what() const throw() {
	return (RED "Index is out of bounds!\n" NRM);
}
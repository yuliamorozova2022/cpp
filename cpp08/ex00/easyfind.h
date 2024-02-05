#ifndef __EASYFIND__
#define __EASYFIND__

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
    const char* what() const throw() {
        return "Integer was not found!\n";
    }
};

template <typename T> 
void easyfind(T cont, int x) {
    if (std::find(cont.begin(), cont.end(), x) != cont.end()) {
        std::cout << "Integer was found!\n";
    }
    else {
        throw NotFoundException();
    }
}

#endif
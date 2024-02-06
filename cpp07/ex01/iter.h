#ifndef __ITER__
#define __ITER__

#include <cstddef>

template <typename T>
void iter(const T *arr, size_t len, void(*func)(T const &)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T>
void iter(T *arr, size_t len, void(*func)(T &)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

#endif
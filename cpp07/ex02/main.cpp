#include "Array.h"
#include <time.h>
#include <ctime>

template <typename T> void printArr(T const &a, int len) {
	for (size_t i = 0; i < static_cast<size_t>(len); i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

#define MAX_VAL 750/*750*/
int main()
{
	// int *a = new int();
	// std::cout << *a << std::endl;
	// Array<int> numbers(3);
	// std::cout << numbers.size() << std::endl;
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	numbers[i] = i;
	// }
	
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		// std::cout << "i = " << i << ", value to set = " << value << std::endl;
    }

	// std::cout << "Numbers array: " << std::endl;
	// printArr(numbers, MAX_VAL);
	// std::cout << "Mirror array: " << std::endl;
	// printArr(mirror, MAX_VAL);

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try {
		std::cout << "try to set 0 value to -2 index of array" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
		std::cout << "try to set 0 value to MAX_VAL index of array" << std::endl;
        numbers[MAX_VAL] = 0;
    }
	catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	try {
		std::cout << "try to set 0 value to 0 index of mirror array" << std::endl;
        mirror[0] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

	// std::cout << "Mirror array: " << std::endl;
	// printArr(mirror, MAX_VAL);

	// Array<int> numbers_new(numbers);
	// std::cout << "Copy numbers array: " << std::endl;
	// printArr(numbers_new, MAX_VAL);

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

	// std::cout << "Numbers array with new values: " << std::endl;
	// printArr(numbers, MAX_VAL);
	// std::cout << "Mirror array: " << std::endl;
	// printArr(mirror, MAX_VAL);
	// std::cout << "Copy numbers array: " << std::endl;
	// printArr(numbers_new, MAX_VAL);

    delete [] mirror;//
	std::cout << "all cool" << std::endl;
    return 0;
}
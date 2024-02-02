#include "iter.h"
//#include <time.h>

template <typename T> void printHalf(T& a) {
    std::cout << a / 2 << " ";
}

template <typename T> void increment(T& a) {
    a++;
}

void printStr(std::string &str) 
{
	std::cout << str << std::endl;
}


int	main()
{
	std::cout << "----------------------------------------------------" << std::endl;
	int arr0[5] = {-70, 7, 256, -777, 0};
	std::cout << "	Int array before: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr0[i] << " ";
	std::cout << std::endl;
	iter(arr0, 5, increment);
	std::cout << "	Int array after: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr0[i] << " ";
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	double arr1[5] = {-70.2, 7.5, 256.6, -777, 0};
	std::cout << "	Double array before: \n";
	for (int i = 0; i < 5; i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	std::cout << "	Double array after:" << std::endl;
	iter(arr1, 5, printHalf);
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::string arr2[5] = {"a", "hi", "256.6", "****", "hell0!"};
	std::cout << "	String array before:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arr2[i] << std::endl;
	std::cout << "	String array after:" << std::endl;
	iter(arr2, 5, printStr);
	std::cout << "----------------------------------------------------" << std::endl;

	return 0;
}
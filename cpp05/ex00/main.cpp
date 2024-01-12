#include "Bureaucrat.h"

int main() {
	Bureaucrat *test1 = new Bureaucrat("Test1", 2);
	std::cout << "First bureaucrat (test1):\n" << "	" << *test1 << "address = " << test1 << std::endl;
	Bureaucrat test2(*test1);
	std::cout << "Copy (test2) bureaucrat:\n" << "	" << test2 << "address = " << &test2 << std::endl;
	Bureaucrat test3;
	test3 = *test1;
	std::cout << "Third (test3) bureaucrat:\n" << "	" << test3 << "address = " << &test3 << std::endl;


	std::cout << "----------------TEST 1-------------------" << std::endl;
	std::cout << "Increase test on test1:" << std::endl;
	try {
		std::cout << "	Should successfully increase test1 by 1 to final grade = 1" << std::endl;
		test1->increaseGrade(1);
		std::cout << "	Should fail increase test1 by -10" << std::endl;
		test1->increaseGrade(-10);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Decrease test on test1:" << std::endl;
	try {
		std::cout << "	Should successfully decrease test1 by 50 to final grade = 51" << std::endl;
		test1->decreaseGrade(50);
		std::cout << "	Should fail decrease test1 by 0" << std::endl;
		test1->decreaseGrade(0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "----------------TEST 2-------------------" << std::endl;
	delete test1;
	std::cout << "copy bureaucrat (test2) after deleting the original:\n" << test2 << std::endl;
	std::cout << "assigned bureaucrat (test3) after deleting the original:\n" << test3 << std::endl;


	std::cout << "----------------TEST 3-------------------" << std::endl;
	std::cout << "Increase and decrease (valid) test on test2:" << std::endl;
	test2.decreaseGrade(50);
	test2.increaseGrade(5);

	std::cout << "----------------TEST 4-------------------" << std::endl;
	try {
		std::cout << "	Should fail decrease test2 by 160" << std::endl;
		test2.decreaseGrade(160);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------TEST 5-------------------" << std::endl;
	std::cout << "	Should fail create test4 with grade 160" << std::endl;
	try {
		Bureaucrat test4 = Bureaucrat("test4", 160);
		std::cout << "Third bureaucrat:\n" << test4 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------end-------------------" << std::endl;
	return 0;
}
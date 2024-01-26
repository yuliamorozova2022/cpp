#include "Identifier.h"

Base* generate(void) {
	switch (rand() % 3) {
		case 0:
			return (std::cout << "Object A created" << std::endl, new A);
		case 1:
			return (std::cout << "Object B created" << std::endl, new B);
		case 2:
			return (std::cout << "Object C created" << std::endl, new C);
		default:
			std::cout << "Something went wrong" << std::endl;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Pointer to object A identified" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Pointer to object B identified" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Pointer to object C identified" << std::endl;
		return;
	}
}

void identify(Base& p) {
	// (void)p;
	try {
		A& test = dynamic_cast<A&>(p);
		std::cout << "Reference to object A identified" << std::endl;
		(void)test;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Dinamic cast to A&:\t" << e.what() << std::endl;
	}
	try {
		B& test = dynamic_cast<B&>(p);
		std::cout << "Reference to object B identified" << std::endl;
		(void)test;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Dinamic cast to B&:\t" <<e.what() << std::endl;
	}
	try {
		C& test = dynamic_cast<C&>(p);
		std::cout << "Reference to object C identified" << std::endl;
		(void)test;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Dinamic cast to C&:\t" << e.what() << std::endl;
	}
}
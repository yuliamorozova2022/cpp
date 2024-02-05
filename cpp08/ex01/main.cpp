#include "Span.h"
#include <cassert>

int main() {
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();
		// fail 
		sp.addNumber(1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Span sp1 = Span(15);
	try {
		sp1.addNumber(9);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.print();
		//fail
		sp1.addRange(6, 19);
		// sp1.addNumber(10);
		// sp1.print();
		//fail
		// sp.addNumber(17);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try {
		sp1.addRange(6, 17);
		sp1.print();
		//fail
		sp1.addNumber(10);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	sp1.print();
	Span sp2 = Span(15000);
	try {
		sp2.print();
		//fail
		sp2.addRange(0, 15000);
		// sp1.addNumber(10);
		sp2.print();
		//fail
		// sp.addNumber(17);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return 0;
}
#include "Span.h"
// #include <cassert>


/* int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
} */
int main() {
	std::cout << "	test0 (small arr):"<< std::endl; 
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(-50);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.print();
		// fail 
			sp.addNumber(1);
		}
		catch(const std::exception& e) {
			std::cerr << "sp.addNumber(1):"<< e.what() << '\n';
		}
		try {
			std::cout << "sp.shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "sp.longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
/* 	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(-50);
			sp.addNumber(17);
			sp.addNumber(18);
			sp.addNumber(11);
			sp.print();
		// fail 
			sp.addNumber(1);
		}
		catch(const std::exception& e) {
			std::cerr << "sp.addNumber(1):"<< e.what() << '\n';
		}
		try {
			std::cout << "sp.shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "sp.longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	} */
	std::cout << "\n	test1 (small arr) addRange():"<< std::endl; 
	{
		Span sp1 = Span(15);
		try {
			sp1.addNumber(9);
			sp1.addNumber(3);
			sp1.addNumber(17);
			sp1.addNumber(9);
			sp1.print();
		//fail
			sp1.addRange(6, 19);
		} catch(const std::exception& e)
		{
			std::cerr << "sp1.addRange(6, 19):" << e.what() << '\n';
		}
		try {
			sp1.addRange(6, 17);
			sp1.print();
		//fail
			sp1.addNumber(10);
		}
		catch(const std::exception& e) {
			std::cerr  << "sp1.addNumber(10):" << e.what() << '\n';
		}
		// sp1.print();
		try {
			//the shortest span must be 0 because there are several '9' in the array
			std::cout << "sp1.shortest span: " << sp1.shortestSpan() << std::endl;
			std::cout << "sp1.longest span: " << sp1.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n	test2 (big arr):"<< std::endl; 
	{
		//test: big container
		Span sp2 = Span(12000);
		try {
			// sp2.print();
			sp2.addRange(0, 12000);
			// sp2.print();
		//fail
			sp2.addNumber(10);
		}
		catch(const std::exception& e) {
			std::cerr << "sp2.addNumber(10):" << e.what() << '\n';
		}
		try {
			std::cout << "sp2.shortest span: " << sp2.shortestSpan() << std::endl;
			std::cout << "sp2.longest span: " << sp2.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n	test3 (very small arr) shortestSpan() & longestSpan():"<< std::endl; 
	{
		//test: too small container
		Span sp3 = Span(3);
		try {
		//fail (empty container)
			std::cout << "sp3.longestSpan():" << sp3.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
		//fail (empty container)
			std::cout << "sp3.shortestSpan():" << sp3.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		sp3.addNumber(9);
		try {
		//fail (one element in container)
			std::cout << "sp3.longestSpan():" << sp3.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
		//fail (one element in container)
			std::cout << sp3.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << "sp3.shortestSpan():" << e.what() << '\n';
		}
		sp3.addNumber(8);
		sp3.print();
		try {
			//2 elements in container
			std::cout << "sp3.longestSpan():" << sp3.longestSpan() << std::endl;
			std::cout << "sp3.shortestSpan():" << sp3.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		sp3.addNumber(4);
		sp3.print();
		try {
			//3 elements in container
			std::cout << "sp3.longestSpan():" << sp3.longestSpan() << std::endl;
			std::cout << "sp3.shortestSpan():" << sp3.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		
	}
	
	return 0;
}
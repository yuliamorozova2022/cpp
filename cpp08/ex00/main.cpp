#include "easyfind.h"

int main() {
	std::cout << "		Vector test:" << std::endl;
	try {
		std::vector <int> g1;
		for (int i = 1; i <= 5; i++)
			g1.push_back(i * 10);
		int x = 40;
		std::cout << "valid try to find x = " << x << " in vector" << std::endl;
		easyfind(g1, x);
		std::cout << " (at position: " << std::distance(g1.begin(), (std::find(g1.begin(), g1.end(), x))) << ")" << std::endl;
		x = 10;
		std::cout << "valid try to find x = " << x << " in vector" << std::endl;
		easyfind(g1, x);
		std::cout << " (at position: " << std::distance(g1.begin(), (std::find(g1.begin(), g1.end(), x))) << ")" << std::endl;
		x = 100;
		std::cout << "wrong try to find x = " << x << " in vector" << std::endl;
		easyfind(g1, x);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


	std::cout << "		Linked list test:" << std::endl;
	try {
		std::list <int> g2;
		for (int i = 1; i <= 5; i++)
			g2.push_back(i * 100);
		int x = 200;
		std::cout << "valid try to find x = " << x << " in list" << std::endl;
		easyfind(g2, x);
		std::cout << " (at position: " << std::distance(g2.begin(), (std::find(g2.begin(), g2.end(), x))) << ")" << std::endl;
		x = 550;
		std::cout << "wrong try to find x = " << x << " in list" << std::endl;
		easyfind(g2, x);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
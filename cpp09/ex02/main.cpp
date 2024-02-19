#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc <= 2) {
		std::cerr << RED "Error. Too few arguments" NRM << std::endl;
		return 1;
	}
	else {
		try {
			PmergeMe pm(argc, argv);
			pm.sort();
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			return 2;
		}
	}
	return 0;
}
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc <= 2) /*&& std::string::(argv[1]) != "autotests") */{
		std::cerr << "Error. Too few arguments" << std::endl;
		return 1;
	}
	/*if (std::string::(argv[1]) == "autotests") {
		//todo
	}*/
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
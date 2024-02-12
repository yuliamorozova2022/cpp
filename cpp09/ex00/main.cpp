#include "BitcoinExchange.hpp"

int main (int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc \"inputfile\"" << std::endl;
		return 1;
	}
	BitcoinExchange b;
	b.readFile(argv[1]);
	return 0;
}
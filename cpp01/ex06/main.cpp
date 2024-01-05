#include "Harl.h"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
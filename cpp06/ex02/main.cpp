#include "Identifier.h"
#include <time.h>

int	main()
{
	Base *test;
	int iter = 15;
   	time_t t;
    /* Intializes random number generator */
   	srand((unsigned) time(&t));

	for (int i = 0; i < iter; i++) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "\tTest iteration " << i << std::endl;
		test = generate();
		identify(test);
		Base& ref = *test;
		identify(ref);
		delete test;
		test = NULL;
	}
	std::cout << "--------------------------------------------" << std::endl;
	return 0;
}
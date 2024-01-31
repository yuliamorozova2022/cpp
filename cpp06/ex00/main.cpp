#include "ScalarConverter.h"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Input looks like: \"./converter [input]\"" << std::endl;
		return (1);
	}
	//std::cout<< argv[1] <<std::endl;
	try
	{
		std::string s = argv[1];
		ScalarConverter::convert(s);/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	return 0;
}
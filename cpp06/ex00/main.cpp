#include "ScalarConverter.h"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Input looks like: \"./scalarconverter [input]\"" << std::endl;
		return (1);
	}
	//std::cout<< argv[1] <<std::endl;
	
	std::string s = argv[1];
	ScalarConverter::convert(s);
	return 0;
}
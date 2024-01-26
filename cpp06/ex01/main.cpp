#include "Serializer.h"

int	main()
{
	Data d;
	Data *data_orig = &d;
	Data *data_new;
	uintptr_t raw;

	data_orig->nbr = 0;
	data_orig->str = "hello";

	std::cout << "The address of data_orig = " << data_orig << std::endl;
	std::cout << "Fields in the structure are: nbr = " << data_orig->nbr << ", str = " << data_orig->str << std::endl;
	std::cout <<  "\t\tSerializing\n" << std::endl;
	raw = Serializer::serialize(data_orig);
	std::cout << "Uintptr_t after serialize = " << raw <<std::endl;

	std::cout <<  "\t\tDeserializing\n" << std::endl;
	data_new = Serializer::deserialize(raw);
	std::cout << "The address of data_new = " << data_new << std::endl;
	std::cout << "Fields in the structure are: nbr = " << data_new->nbr << ", str = " << data_new->str << std::endl;

	std::cout << "Result of expression \'data_orig == data_new\' is " << (data_orig == data_new) << std::endl;

	return 0;
}
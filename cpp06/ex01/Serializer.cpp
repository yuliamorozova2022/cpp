#include "Serializer.h"
//-------- Orthodox Canonical Form ---------
Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& orig) {
	(void)orig;
	std::cout << "Copy constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Destructor called" << std::endl;
}

Serializer& Serializer::operator = (const Serializer& orig) {
	if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

//---------------- methods ------------------
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
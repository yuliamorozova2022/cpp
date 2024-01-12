
#include "Ice.h"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Default constructor. Ice created" << std::endl;
}

Ice::Ice(const Ice& orig) : AMateria("ice") {
	_type = orig.getType();
	// std::cout << "Copy constructor. Materia ice created" << std::endl;
}

Ice& Ice::operator = (const Ice& orig) {
	if (this == &orig) {
		return *this;
	}
	// std::cout << "Assignment operator. Ice created" << std::endl;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Destructor. Ice deleted" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria* new_one = new Ice();
	return new_one;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
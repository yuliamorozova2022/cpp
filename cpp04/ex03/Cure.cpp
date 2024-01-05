
#include "Cure.h"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default constructor. Cure created" << std::endl;
}

Cure::Cure(const Cure& orig) : AMateria("cure") {
	_type = orig.getType();
	std::cout << "Copy constructor. Materia Cure created" << std::endl;
}

Cure& Cure::operator = (const Cure& orig) {
	if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. Cure created" << std::endl;
	return *this;
}

Cure::~Cure() {
	std::cout << "Destructor. Cure deleted" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria* new_one = new Cure();
	return new_one;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
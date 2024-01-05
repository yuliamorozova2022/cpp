
#include "AMateria.h"

AMateria::AMateria() {
	_type = "";
	std::cout << "Default constructor. Materia created" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	_type = type;
	std::cout << "String constructor. Materia \"" << _type << "\" created" << std::endl;
}

AMateria::AMateria(const AMateria& orig) {
	_type = orig.getType();
	std::cout << "Copy constructor. Materia \"" << _type << "\" created" << std::endl;
}

AMateria& AMateria::operator = (const AMateria& orig) {
	if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. Materia \"" << _type << "\" created" << std::endl;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Destructor for materia \"" << _type << "\" called" << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* just empty materia in use on " << target.getName() << " *" << std::endl;
}
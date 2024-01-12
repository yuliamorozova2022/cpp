
#include "MateriaSource.h"
// #include "Ice.h"
// #include "Cure.h"

void MateriaSource::clearStorage() {
	for (int i = 0; i < STORAGESIZE; i++) {
		if (_storage[i] != NULL) {
			delete _storage[i];
			_storage[i] = NULL;
		}
	}
	std::cout << "Storage cleared" << std::endl; // REMOVE!!!
}

void MateriaSource::fillStorage(const MateriaSource& orig) {
	for (int i = 0; i < STORAGESIZE; i++) {
		if (orig._storage[i] != NULL) {
			_storage[i] = orig._storage[i]->clone();
			if (i == STORAGESIZE - 1) {
				_full = true;
			}
		}
	}
	// std::cout << "Storage filled" << std::endl; // REMOVE!!!
}

MateriaSource::MateriaSource() {
	for (int i = 0; i < STORAGESIZE; i++) {
		_storage[i] = NULL;
	}
	_full = false;
	std::cout << "Default constructor. MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& orig) {
	_full = false;
	fillStorage(orig);
	std::cout << "Copy constructor. MateriaSource copied" << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& orig) {
	if (this != &orig) {
		return *this;
	}
	clearStorage();
	_full = false;
	fillStorage(orig);
	std::cout << "Assignment operator. MateriaSource copied" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	clearStorage();
	std::cout << "Default destructor. MateriaSource deleted" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (_full == true) {
		std::cout << "Storage is full. Can't learn materia " << materia->getType() << std::endl;
		return;
	}
	if (materia == NULL) {
		std::cout << "Invalid materia. Can't learn it " << std::endl;
		return;
	}
	for (int i = 0; i < STORAGESIZE; i++) {
		if (_storage[i] == NULL) {
			_storage[i] = materia->clone();
			if (i == STORAGESIZE - 1) {
				_full = true;
			}
			std::cout << "Materia " << _storage[i]->getType() << " learned" << std::endl;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < STORAGESIZE; i++) {
		if (_storage[i] && type.compare(_storage[i]->getType()) == 0) {
			return _storage[i]->clone();
		}
	}
	std::cout << "Can't create materia " << type << std::endl;
	return NULL;
}
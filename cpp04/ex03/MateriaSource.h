#ifndef __MATERIASOURCE__
#define __MATERIASOURCE__

#define STORAGESIZE 4

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource& orig);
	MateriaSource& operator = (const MateriaSource& orig);
	~MateriaSource();

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
private:
	AMateria *_storage[STORAGESIZE];
	bool _full;
	void clearStorage();
	void fillStorage(const MateriaSource& orig);
};

#endif
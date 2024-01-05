#ifndef __CURE__
#define __CURE__

#include <iostream>
#include "AMateria.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& orig);
	Cure& operator = (const Cure& orig);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
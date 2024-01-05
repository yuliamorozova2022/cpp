#ifndef __ICE__
#define __ICE__

#include <iostream>
#include "AMateria.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& orig);
	Ice& operator = (const Ice& orig);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
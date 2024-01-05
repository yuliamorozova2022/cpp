#ifndef __AMATERIA__
#define __AMATERIA__

#include <iostream>
#include "ICharacter.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(const AMateria& orig);
		AMateria(std::string const & type); // constructor from the task
		virtual ~AMateria();
		AMateria& operator = (const AMateria& orig);

		//[everything further is from the task]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
};

#endif
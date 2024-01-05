#ifndef __CHARACTER__
#define __CHARACTER__

#define INVENT_SIZE 4

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

#include "ICharacter.h"

class Character : public ICharacter {
public:
	Character();
	Character(std::string nm);
	Character(const Character& orig);
	~Character();
	Character& operator = (const Character& orig);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	AMateria *_inventory[INVENT_SIZE];
	std::string _name;
};

#endif
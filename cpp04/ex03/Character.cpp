
#include "Character.h"

Character::Character() {
	for (int i = 0; i < INVENT_SIZE; i++) {
		_inventory[i] = NULL;
	}
	_name = "";
	std::cout << "Default constructor. Character created" << std::endl;
}

Character::Character(std::string nm) {
	for (int i = 0; i < INVENT_SIZE; i++) {
		_inventory[i] = NULL;
	}
	_name = nm;
	std::cout << "String constructor. Character " << _name << " created" << std::endl;
}

Character::Character(const Character& orig) {
	_name = orig.getName();
	for (int i = 0; i < INVENT_SIZE; i++) {
		if (orig._inventory[i] != NULL) {
			_inventory[i] = orig._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
	std::cout << "Copy constructor. Character " << _name << " copied" << std::endl;
}

Character& Character::operator = (const Character& orig) {
	if (this == &orig) {
		return *this;
	}
	_name = orig.getName();
	for (int i = 0; i < INVENT_SIZE; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < INVENT_SIZE; i++) {
		if (orig._inventory[i] != NULL) {
			_inventory[i] = orig._inventory[i]->clone();
		}
	}
	std::cout << "Assignment operator. Character " << _name << " copied" << std::endl;
	return *this;
}

Character::~Character() {
	std::cout << "Default destructor. Character " << getName() << " deleted" << std::endl;
	for (int i = 0; i < INVENT_SIZE; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "Can't add invalid materia" << std::endl;
		return;
	}
	for (int i = 0; i < INVENT_SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << "Materia " << _inventory[i]->getType() << " was added to the inventory of the character " << getName() << std::endl;
			return;
		}
	}
	std::cout << "Inventory is already full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > INVENT_SIZE - 1) {
		std::cout << "Invalid index!" << std::endl;
		return;
	} 
	if (_inventory[idx] == NULL) {
		std::cout << "Empty slot [" << idx << "] in inventory!" << std::endl;
		return;
	}
	
	std::cout << "Materia " << _inventory[idx]->getType() << " at index [" << idx << "] was unequipped" << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > INVENT_SIZE - 1) {
		std::cout << "Invalid index [" << idx << "]!" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "Empty slot [" << idx << "] in inventory!" << std::endl;
		return;
	}

	_inventory[idx]->use(target);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:45:18 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include "Brain.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

Dog::Dog() {
	_type = "domestic dog";
	_brain = new Brain();
	_brain->setIdeas("Woof!");
	std::cout << "Dog \"" << _type << "\" was born" << std::endl;
}

Dog::Dog(const Dog& orig) {
	_type = orig.getType();
	_brain = new Brain();
	_brain->setIdeas("Woof!");
	std::cout << "Dog \"" << _type << "\" appeared"<< std::endl;
}

Dog& Dog::operator= (const Dog& cp) {
	if (this == &cp) {
		return *this;
	}
	_type = cp.getType();
	_brain = new Brain();
	_brain->setIdeas("Woof!");
	std::cout << "Dog \"" << _type << "\" was assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog \"" << _type << "\" died" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog \"" << _type << "\" makes sound: WOOF!WOOF" << std::endl;
}

void Dog::showIdeas() const {
	_brain->showIdeas();
}
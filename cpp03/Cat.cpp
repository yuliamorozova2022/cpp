/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:47:34 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include "Brain.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

Cat::Cat() {
	_type = "domestic cat";
	_brain = new Brain();
	_brain->setIdeas("Mew!");
	std::cout << "Cat \"" << _type << "\" was born" << std::endl;
}

Cat::Cat(const Cat& orig) {
	// std::cout << "		0"<< std::endl;
	// _type = orig.getType();
	// std::cout << "		1	"<< _type<< std::endl;
	// std::cout << "		2_0	"<< &orig._brain<< std::endl;
	_brain = new Brain(*orig._brain);
	// std::cout << "		2	"<< &_brain<< std::endl;
	
	_brain->setIdeas("Mew!");
	// std::cout << "		3	ideas setted"<< std::endl;
	std::cout << "Copy cat \"" << _type << "\" appeared" << std::endl;
}

Cat& Cat::operator= (const Cat& cp) {
	if (this == &cp) {
		return *this;
	}
	_type = cp.getType();
	_brain = new Brain(*cp._brain);
	_brain->setIdeas("Mew!");
	std::cout << "Cat \"" << _type << "\" was assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat \"" << _type << "\" died" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat \"" << _type << "\" makes sound: MEW!MEW!" << std::endl;
}

void Cat::showIdeas() const {
	_brain->showIdeas();
}
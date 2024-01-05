/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:39:21 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

Animal::Animal() {
	_type = "undefined animal";
	std::cout << "Animal \"" << _type << "\" was born" << std::endl;
}

Animal::Animal(const Animal& orig) {
	_type = orig.getType();
	std::cout << "Animal \"" << _type << "\" appeared" << std::endl;
}

Animal& Animal::operator= (const Animal& cp) {
	if (this == &cp) {
		return *this;
	}
	_type = cp.getType();
	std::cout << "Animal \"" << _type << "\" was assigned" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal \"" << _type << "\" died" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal \"" << _type << "\" makes sound: \" \"" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
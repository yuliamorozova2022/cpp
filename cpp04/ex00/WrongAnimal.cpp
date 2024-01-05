/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:40:35 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

WrongAnimal::WrongAnimal() {
	_type = "Wrong animal";
	std::cout << "Animal \"" << _type << "\" was born" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& orig) {
	_type = orig.getType();
	std::cout << "Animal \"" << _type << "\" appeared" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& cp) {
	if (this == &cp) {
		return *this;
	}
	_type = cp.getType();
	std::cout << "Animal \"" << _type << "\" was assigned" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Animal \"" << _type << "\" died" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Animal \"" << _type << "\" makes sound: ......!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
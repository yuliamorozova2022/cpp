/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:39:52 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

Cat::Cat() {
	_type = "domestic cat";
	std::cout << "Cat \"" << _type << "\" was born" << std::endl;
}

Cat::Cat(const Cat& orig) {
	_type = orig.getType();
	std::cout << "Cat \"" << _type << "\" appeared" << std::endl;
}

Cat& Cat::operator= (const Cat& cp) {
	if (this == &cp) {
		return *this;
	}
	_type = cp.getType();
	std::cout << "Cat \"" << _type << "\" was assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat \"" << _type << "\" died" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat \"" << _type << "\" makes sound: MEW!MEW!" << std::endl;
}

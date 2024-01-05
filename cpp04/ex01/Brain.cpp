/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:42:47 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

Brain::Brain() {
	for (int i = 0; i < SIZE; i++) {
		// new (_ideas + i) std::string();
		_ideas[i] = "";
	}
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& orig) {
	// ideas = new std::string[SIZE];
	for (int i = 0; i < SIZE; i++) {
		_ideas[i] = orig._ideas[i];
	}
	std::cout << "Brain copy appeared" << std::endl;
}

Brain& Brain::operator= (const Brain& cp) {
	if (this == &cp) {
		return *this;
	}
	for (int i = 0; i < SIZE; i++) {
		_ideas[i] = cp._ideas[i];
	}
	std::cout << "Brain was assigned" << std::endl;
	return *this;
}

Brain::~Brain() {
	// delete [] _ideas;
	std::cout << "Brain died" << std::endl;
}

void Brain::setIdeas(std::string idea) {
	for (int i = 0; i < SIZE; i++) {
		_ideas[i] = _ideas[i] + idea;
	}
}
void Brain::showIdeas() const {
	for (int i = 0; i < SIZE; i++) {
		std::cout << _ideas[i];
		if (i != SIZE - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}
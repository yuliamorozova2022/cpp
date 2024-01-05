/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:27 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

FragTrap::FragTrap() {
	setHit(100);
	setEnergy(100);
	setAttack(30);
}

FragTrap::FragTrap(std::string nm) {
	setName(nm);
	setHit(100);
	setEnergy(100);
	setAttack(30);
	std::cout << "FragTrap " << nm << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& orig) {
	setName(orig.getName() + "_copy");
	setEnergy(orig.getEnergy());
	setHit(orig.getHp());
	setAttack(orig.getAttack());
	std::cout << "FragTrap " << getName() << " appeared" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& ct) {
	setName(ct.getName());
	setEnergy(ct.getEnergy());
	setHit(ct.getHp());
	setAttack(ct.getAttack());
	std::cout << "FragTrap " << getName() << " was assigned" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " says: High Fives Guys!" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 15:26:01 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
*/

ScavTrap::ScavTrap() {
	setHit(100);
	setEnergy(50);
	setAttack(20);
	std::cout << "ScavTrap default counstructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nm) {
	setName(nm);
	setHit(100);
	setEnergy(50);
	setAttack(20);
	std::cout << "ScavTrap " << getName() << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& orig) {
	setName(orig.getName() + "_copy");
	setEnergy(orig.getEnergy());
	setHit(orig.getHp());
	setAttack(orig.getAttack());
	std::cout << "ScavTrap " << getName() << " appeared" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& ct) {
	setName(ct.getName());
	setEnergy(ct.getEnergy());
	setHit(ct.getHp());
	setAttack(ct.getAttack());
	std::cout << "ScavTrap " << getName() << " was assigned" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "SkavTrap " << getName() << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (getHp() == 0) {
		std::cout << "Scav " << getName() << " is dead" << std::endl;
		return;
	}
	if (getEnergy() == 0) {
		std::cout << "ScavTrap " << getName() << " tries to attack " << target << ", but doesn't have enouth energy" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << /* ", causing " << attack_p << " points of damage!" << */ std::endl;
	setEnergy(getEnergy() - 1);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
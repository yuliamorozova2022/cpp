/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 15:22:38 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default counstructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nm) {
	name = nm;
	energy = 10;
	hit = 10;
	attack_p = 0;
	std::cout << "ClapTrap " << name << " appeared" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& orig) {
	name = orig.getName() + "_copy";
	energy = orig.getEnergy();
	hit = orig.getHp();
	attack_p = orig.getAttack();
	std::cout << "ClapTrap " << name << " appeared" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& ct) {
	name = ct.getName();
	energy = ct.getEnergy();
	hit = ct.getHp();
	attack_p = ct.getAttack();
	std::cout << "ClapTrap " << name << " was assigned" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hit == 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy == 0) {
		std::cout << "ClapTrap " << name << " tries to attack " << target << ", but doesn't have enouth energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << /* ", causing " << attack_p << " points of damage!" << */ std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit == 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " of damage" << std::endl;
	if (hit <= amount) {
		std::cout << "ClapTrap " << name << " killed" << std::endl;
		hit = 0;
		return;
	}
	hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit == 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy < 1) {
		std::cout << "ClapTrap " << name << " doesn't have enouth energy to repair itself" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " repaired itself by " << amount << " points" << std::endl;
	hit += amount;
	energy -= amount;
}

std::string ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHp() const {
	return hit;
}

unsigned int ClapTrap::getEnergy() const {
	return energy;
}

unsigned int ClapTrap::getAttack() const {
	return attack_p;
}

void ClapTrap::setHit(unsigned int value) {
	hit = value;
}

void ClapTrap::setAttack(unsigned int value) {
	attack_p = value;
}

void ClapTrap::setEnergy(unsigned int value) {
	energy = value;
}

void ClapTrap::setName(std::string nm) {
	name = nm;
}
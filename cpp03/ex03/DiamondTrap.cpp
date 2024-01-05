/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/11 13:27:05 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

/* class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(const DiamondTrap& orig);
	DiamondTrap& operator = (const DiamondTrap& ct);
}; */

DiamondTrap::DiamondTrap() {
	std::cout << "basic constructor for diamond: fragHP=" <<FragTrap::getHp() << ", scavEnergy="<< ScavTrap::getEnergy() << ", fragAttack=" << FragTrap::getAttack() << std::endl;
	setHit(FragTrap::getHp());
	setAttack(FragTrap::getAttack());
	setEnergy(ScavTrap::getEnergy());
	std::cout << "res: HP=" << hit << ", Energy="<< energy << ", Attack=" << attack_p << std::endl;
	
}

DiamondTrap::DiamondTrap(std::string nm) : ClapTrap(nm + "_clap_name") {
	name = nm;
	
	std::cout << "str constructor for diamond: fragHP=" <<FragTrap::getHp() << ", scavEnergy="<< ScavTrap::getEnergy() << ", fragAttack=" << FragTrap::getAttack() << ", name=" <<name << std::endl;
	
	setHit(FragTrap::getHp());
	setEnergy(ScavTrap::getEnergy());
	setAttack(FragTrap::getAttack());

std::cout << "res: HP=" << hit << ", Energy="<< energy << ", Attack=" << attack_p << ", name=" << name << std::endl;
	// FragTrap::setHit();
	// ScavTrap::setEnergy();
	// FragTrap::setAttack();
	std::cout << "res: HP=" << hit << ", Energy="<< energy << ", Attack=" << attack_p << ", name=" << name << std::endl;

	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& ct) {
	setName(ct.getName());
	setEnergy(ct.getEnergy());
	setHit(ct.getHp());
	setAttack(ct.getAttack());
	std::cout << "DiamondTrap " << getName() << " was assigned" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << name << std::endl;
	std::cout << "I am ClapTrap " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const {
	return name;
}
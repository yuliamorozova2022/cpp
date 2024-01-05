/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:41 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include "FragTrap.h"

int	main() {
	ClapTrap one("One");
	ClapTrap two("Two");
	ScavTrap three("Three");
	FragTrap four("Four");
	std::cout << "--------------" << std::endl;
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	
	for (int i = 0; i < 4; i++) {
		one.attack("Two");
		if (one.getEnergy() > 0) {
			two.takeDamage(1);
			if (i == 2) {
				two.beRepaired(3);
			}
		}
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	
	for (int i = 0; i < 11; i++) {
		if (two.getHp() == 0) {
			std::cout << "ClapTrap " << two.getName() << " is dead" << std::endl;
			break;		
		}
		two.attack("One");
		if (two.getEnergy() > 0) {
			one.takeDamage(1);
		}
		
		// if (i == 6) {
		// 	one.beRepaired(0);
		// }
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	
	for (int i = 0; i < 4; i++) {
		if (one.getHp() == 0) {
			std::cout << "ClapTrap " << one.getName() << " is dead" << std::endl;
			break;		
		}
		if (i < 2) {
			one.attack("Three");
			if (three.getEnergy() > 0) {
				three.takeDamage(10);
			}
		}
		else {
			three.guardGate();
		}
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	for (int i = 0; i < 4; i++) {
		if (three.getHp() == 0) {
			std::cout << "ScavTrap " << three.getName() << " is dead" << std::endl;
			break;		
		}
		if (i < 2) {
			three.attack("Four");
			if (four.getEnergy() > 0) {
				four.takeDamage(60);
			}
			if (four.getHp() == 0) {
				std::cout << "FragTrap " << four.getName() << " is dead" << std::endl;
				break;
			}
		}
		else {
			four.highFivesGuys();
		}
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	std::cout << "--------------" << std::endl;
	return 0;
}
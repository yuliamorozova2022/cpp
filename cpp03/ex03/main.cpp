/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/11 12:51:39 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
// #include "FragTrap.h"

int	main() {
	ScavTrap one("One");
	FragTrap two("Two");
	DiamondTrap three("Three");
	std::cout << "--------------" << std::endl;
	/*std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	
	//test ScavTrap Three
	 for (int i = 0; i < 4; i++) {
		if (one.getHp() == 0) {
			std::cout << "ScavTrap " << one.getName() << " is dead" << std::endl;
			break;		
		}
		if (i < 3) {
			one.attack("Three");
			if (three.getEnergy() > 0) {
				three.takeDamage(10);
			}
		}
		else {
			three.whoAmI();
		}
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	// test FragTrap Four
	for (int i = 0; i < 3; i++) {
		if (two.getHp() == 0) {
			std::cout << "FragTrap " << two.getName() << " is dead" << std::endl;
			break;		
		}
		if (i < 2) {
			two.attack("Three");
			if (three.getEnergy() > 0) {
				three.takeDamage(20);
			}
			if (three.getHp() == 0) {
				std::cout << "FragTrap " << three.getName() << " is dead" << std::endl;
				break;
			}
		}
		else {
			three.whoAmI();
		}
	}
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	
	three.attack("One");
	one.takeDamage(5);
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	
	std::cout << "--------------" << std::endl;
	
	DiamondTrap four;
	four = three;
	four.setName("Four");
	std::cout << three.getName() << " hp: " << three.getHp() << ", energy: " << three.getEnergy() << ", attack: " << three.getAttack() << std::endl;
	std::cout << four.getName() << " hp: " << four.getHp() << ", energy: " << four.getEnergy() << ", attack: " << four.getAttack() << std::endl;
	 */std::cout << "--------------" << std::endl;
	return 0;
}
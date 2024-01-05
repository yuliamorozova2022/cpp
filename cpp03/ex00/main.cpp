/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 14:59:14 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main() {
	ClapTrap one("One");
	ClapTrap two("Two");
	std::cout << "--------------" << std::endl;
	std::cout << one.getName() << " hp: " << one.getHp() << ", energy: " << one.getEnergy() << ", attack: " << one.getAttack() << std::endl;
	std::cout << two.getName() << " hp: " << two.getHp() << ", energy: " << two.getEnergy() << ", attack: " << two.getAttack() << std::endl;
	
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
	std::cout << "--------------" << std::endl;
	return 0;
}
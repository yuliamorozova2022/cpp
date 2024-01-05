/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:29:50 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 18:05:22 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string n) : name(n) {
	// name = n;
	weapon = NULL;
}

HumanB::~HumanB() {
	;
}

void HumanB::attack() {
	if (weapon == NULL)
		std::cout << name << "does't have weapon!"  << std::endl;
	else
		std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w) {
	weapon = &w;
}
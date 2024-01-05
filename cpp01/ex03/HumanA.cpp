/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:29:50 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/23 13:01:08 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
/* 
class HumanA {
	private:
		std::string name;
		Weapon& weapon;
	public:
		
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
};
 */

HumanA::HumanA(std::string n, Weapon& w) : name(n), weapon(w) {
	;
}

HumanA::~HumanA() {
	;
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
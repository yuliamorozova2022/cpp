/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:45:24 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:40:08 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {
	name = "";
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " was killed" << std::endl;
}

void Zombie::give_name(std::string _name) {
	name = _name;
}

void Zombie::announce(void) {
	std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
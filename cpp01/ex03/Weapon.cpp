/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:12:11 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:39:05 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string name) {
	type = name;
}

Weapon::~Weapon() {
	;
}

const std::string& Weapon::getType(void) {
	return(type);
}

void Weapon::setType(std::string new_type) {
	type = new_type;
}
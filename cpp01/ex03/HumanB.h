/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:11:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:56 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string n);
		~HumanB();
		void attack();
		void setWeapon(Weapon& w);
};

#endif
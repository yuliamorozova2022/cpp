/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:11:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:38:30 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
	private:
		std::string name;
		Weapon& weapon;
	public:
		
		HumanA(std::string n, Weapon& w);
		~HumanA();
		void attack();
};

#endif
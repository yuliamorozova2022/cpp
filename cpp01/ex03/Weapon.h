/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:11:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:38:35 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

# include <iostream>
// # include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string name);
		~Weapon();
		const std::string& getType(void);
		void setType(std::string new_type);
};


#endif
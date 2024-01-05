/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:45:30 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:40:03 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
// # include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void give_name(std::string _name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
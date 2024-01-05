/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:44:25 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:39:20 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
 /*
  new /it's operator/: 
	Attempts to allocate and initialize an object or array of objects of the
	specified or wildcard type and returns an appropriately specified non-null
	pointer to the object (or to the initial array object).
*/
/* 
Zombie* newZombie(std::string name) {
	Zombie *newborn = new Zombie();
	newborn->give_name(name);
	return (newborn);
} */

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1)
		return NULL;
	// (void)name;
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		horde[i].give_name(name);
	return (horde);
}
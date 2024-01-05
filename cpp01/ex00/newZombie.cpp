/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:31 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:40:23 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
 /*
  new /it's operator/: 
	Attempts to allocate and initialize an object or array of objects of the
	specified or wildcard type and returns an appropriately specified non-null
	pointer to the object (or to the initial array object).
*/

Zombie* newZombie(std::string name) {
	Zombie *newborn = new Zombie();
	newborn->give_name(name);
	return (newborn);
}
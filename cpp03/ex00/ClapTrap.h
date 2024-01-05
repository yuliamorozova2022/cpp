/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/24 11:44:16 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string nm);
	ClapTrap(const ClapTrap& orig);
	~ClapTrap();
	
	ClapTrap& operator = (const ClapTrap& ct);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void  beRepaired(unsigned int amount);
	std::string getName() const;
	unsigned int getHp() const;
	unsigned int getEnergy() const;
	unsigned int getAttack() const;
private:
	std::string name;
	unsigned int hit;
	unsigned int energy;
	unsigned int attack_p;
};

#endif
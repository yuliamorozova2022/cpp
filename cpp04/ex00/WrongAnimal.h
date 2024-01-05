/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:40:40 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& orig);
	virtual ~WrongAnimal();
	WrongAnimal& operator = (const WrongAnimal& cp);
	
	void virtual makeSound() const;
	std::string getType() const;
protected:
	std::string _type;
};

#endif

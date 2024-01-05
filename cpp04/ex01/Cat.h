/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:22 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.h"
#include "Brain.h"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& orig);
	~Cat();
	Cat& operator = (const Cat& cp);
	
	void makeSound() const;
	void showIdeas() const;
private:
	Brain* _brain;
};

#endif

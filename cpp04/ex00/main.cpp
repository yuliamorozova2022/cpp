/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/14 13:59:24 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Cat.h"
#include "WrongCat.h"
#include "Dog.h"

int	main() {

	// const Animal* meta = new Animal();
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	// const Animal* i = new Cat();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	return 0;
}
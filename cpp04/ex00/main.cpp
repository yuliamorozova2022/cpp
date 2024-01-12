/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 19:12:15 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
// #include "WrongCat.h"
#include "Dog.h"

int	main() {
	std::cout << "-------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "-----------------------------" << std::endl;
	// const WrongAnimal* meta = new WrongAnimal();
	// std::cout << "-----------------------------" << std::endl;
	const Animal* dg = new Dog();
	std::cout << "-----------------------------" << std::endl;
	const Animal* ct = new Cat();
	// const WrongAnimal* ct = new WrongCat();
	std::cout << "-----------------------------" << std::endl;
	std::cout << dg->getType() << " " << std::endl;
	std::cout << ct->getType() << " " << std::endl;
	ct->makeSound(); //will output the cat sound!
	dg->makeSound();
	meta->makeSound();
	std::cout << "-----------------------------" << std::endl;
	delete ct;
	std::cout << "-----------------------------" << std::endl;
	delete dg;
	std::cout << "-----------------------------" << std::endl;
	delete meta;
	std::cout << "-------------------------------------------" << std::endl;
	return 0;
}
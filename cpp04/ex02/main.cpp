/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2024/01/03 17:27:28 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
// #include "WrongCat.h"
#include "Dog.h"

int	main() {
	std::cout << "first test\n____________" << std::endl;
	std::cout << "____________" << std::endl;
	const Animal* dg = new Dog();
	std::cout << "____________" << std::endl;
	const Animal* ct = new Cat();
	std::cout << "____________" << std::endl;
	std::cout << "Animal type for dg is :	" << dg->getType() << std::endl;
	std::cout << "Animal type for ct is :	" << ct->getType() << std::endl;
	std::cout << "**************" << std::endl;
	
	ct->makeSound();//will output the cat sound!
	std::cout << "Cat's (i) ideas: ";
	ct->showIdeas();//will output the cat ideas!
	std::cout << "**************" << std::endl;
	
	dg->makeSound();//will output the dog sound!
	std::cout << "Dog's (j) ideas: ";
	dg->showIdeas();//will output the dog ideas!
	std::cout << "**************" << std::endl;
	
	Cat test = *(const Cat*) ct;
	std::cout << "test address = " << &test << ", orig address = " << &ct << std::endl;
	delete ct;
	delete dg;
	
	std::cout << "test is still alive:		\n";
	test.makeSound();//will output the test(cat) sound!
	test.showIdeas();
	
	std::cout << "______________________________\nsecond test" << std::endl;
	Cat* orig = new Cat();
	Cat test1 = Cat(*orig);
	std::cout << "test1 address = " << &test1 << ", orig address = " << &orig << std::endl;
	delete orig;
	std::cout << "test1 is still alive:		\n";
	test1.makeSound();//will output the test(cat) sound!
	test1.showIdeas();
	
	
	std::cout << "______________________________\nthird test" << std::endl;
	int	N = 4;
	const	Animal*	crowd[N];
	std::cout << "____________" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "i = " << i << std::endl;
		if (i % 2 == 0) {
			crowd[i] = new Cat();
			std::cout << "____________" << std::endl;
		}
		else {
			crowd[i] = new Dog();
			std::cout << "____________" << std::endl;
		}
	}
	
	std::cout << "**************" << std::endl;
	for (int i = 0; i < N; i++) {
		crowd[i]->showIdeas();
		std::cout << "**************" << std::endl;
	}
	
	std::cout << "____________" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "i = " << i << std::endl;
		delete crowd[i];
		std::cout << "____________" << std::endl;
	}
	return 0;
}
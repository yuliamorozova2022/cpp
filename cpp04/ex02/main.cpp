/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/20 21:30:05 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
// #include "WrongCat.h"
#include "Dog.h"

int	main() {
	std::cout << "first test\n____________" << std::endl;
	// const Animal* meta = new Animal();
	// std::cout << "____________" << std::endl;
	// const WrongAnimal* meta = new WrongAnimal();
	// const WrongAnimal* i = new WrongCat();
	const Animal* j = new Dog();
	std::cout << "____________" << std::endl;
	const Animal* i = new Cat();
	std::cout << "____________" << std::endl;
	std::cout << "Animal type for j is :	" << j->getType() << std::endl;
	std::cout << "Animal type for i is :	" << i->getType() << std::endl;
	std::cout << "**************" << std::endl;
	i->makeSound();//will output the cat sound!
	std::cout << "Cat's (i) ideas: ";
	i->showIdeas();//will output the cat ideas!
	std::cout << "**************" << std::endl;
	j->makeSound();//will output the dog sound!
	std::cout << "Dog's (j) ideas: ";
	j->showIdeas();//will output the dog ideas!
	std::cout << "**************" << std::endl;
	// meta->makeSound();//will output the animal sound!
	// std::cout << "Undefined animal's [meta] ideas: ";
	// meta->showIdeas();//will output the animal ideas!
	// std::cout << "**************" << std::endl;
	Cat test = *(const Cat*) i;
    Animal & pCat = const_cast<Animal &>(*i);
	pCat.showIdeas();
	std::cout << "test address = " << &test << ", i address = " << &i << std::endl;
	delete i;
	delete j;
	// delete meta;
	std::cout << "test is still alive:		";
	test.makeSound();//will output the test(cat) sound!
	test.showIdeas();
	
	std::cout << "______________________________\nsecond test" << std::endl;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:46 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:40:31 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	std::cout << "Creating zombie on stack" << std::endl;
	randomChump("STACK");
	//object will be destroyed by destructor automatically

	Zombie *zzz;
	std::cout << "Creating zombie in heap" << std::endl;
	zzz = newZombie("HEAP");
	zzz->announce();
	//object zzz has to be destroyed by delete operator manually
	delete zzz;
	return 0;
}
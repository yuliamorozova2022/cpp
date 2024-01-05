/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:46 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:39:54 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	int number = 7;
	// //object horde1 has to be destroyed by delete operator manually
	Zombie *horde;
	horde = zombieHorde(number, "Noname");
	if (horde) {
		for (int i = 0; i < number; i++) {
			horde[i].announce();
		}
	}
	std::cout << "Deleting zombie horde:" << std::endl;
	if (horde == NULL)
		std::cout << "(empty horde)" << std::endl;
	delete [] horde;
	return 0;
}
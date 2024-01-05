/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:06:34 by ymorozov          #+#    #+#             */
/*   Updated: 2023/10/20 17:38:43 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;
	std::cout << "The memory address of string variable: <" << &str 
		<< "> value of string: <" << str << ">" << std::endl;
	std::cout << "The memory address of stringPTR: <" << stringPTR
		<< "> value of stringPTR: <" << *stringPTR << ">" << std::endl;
	std::cout << "The memory address of stringREF: <" << &stringREF
		<< "> value of stringREF: <" << stringREF << ">" << std::endl;
	return 0;
}
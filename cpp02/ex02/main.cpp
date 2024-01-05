/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:56:12 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/14 16:50:20 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int main() {
// Fixed a;
// std::cout << "a = "<< a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << --a << std::endl;
// std::cout << a << std::endl;
// std::cout << a-- << std::endl;
// std::cout << a << std::endl;
// std::cout << a-- << std::endl;
// std::cout << a << std::endl;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << "b = " << b << std::endl;
// Fixed const c( Fixed( 10.625f ) + Fixed( 7.75f ) );
// std::cout << "c = " << c << std::endl;
// std::cout << "max: " << Fixed::max( a, b ) << std::endl;
// std::cout << "min: " << Fixed::min( a, b ) << std::endl;

Fixed a;
Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
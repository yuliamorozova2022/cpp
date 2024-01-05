/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:15 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/16 13:55:17 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed () {
    nbr = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    nbr = copy.getRawBits();
}

Fixed &Fixed::operator = (const Fixed& fix) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fix) {
        nbr = fix.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return nbr;
}

void Fixed::setRawBits(int const raw) {
    nbr = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
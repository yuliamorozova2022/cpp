/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:59 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/29 13:47:00 by yuliamorozo      ###   ########.fr       */
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
    if (this == &fix) {
        return *this;
    }
    nbr = fix.getRawBits();
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
//___________________________________________________________________________

Fixed::Fixed (const int value) {
    // nbr = value * 256;
    nbr = value * (1 << 8);
    std::cout << "         (1 << 8)=" << (1 << 8) << " value=" << value << std::endl;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float value) {
    // nbr = roundf(value * 256);
    nbr = roundf(value * (1 << 8));
    std::cout << "         (1 << 8)=" << (1 << 8) << " value=" << value << std::endl;
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const {
    // return (float)nbr / 256;
    return (float)nbr / (1 << 8);
}

int Fixed::toInt() const {
    // return (int)nbr / 256;
    std::cout << "          1 /(1 << 8)=" << 1 /(1 << 8) << std::endl;
    return (int)nbr / (1 << 8);
}

std::ostream& operator << (std::ostream& outstream, const Fixed& fixed) {
    outstream << fixed.toFloat();
    return outstream;
}
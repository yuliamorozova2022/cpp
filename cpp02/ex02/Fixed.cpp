/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:59 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/14 16:52:27 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed () {
    nbr = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    // std::cout << "Copy constructor called" << std::endl;
    nbr = copy.getRawBits();
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return nbr;
}

void Fixed::setRawBits(int const raw) {
    nbr = raw;
    // std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed (const int value) {
    nbr = value * 256;
    // std::cout << "Int constructor called for value: " << value << std::endl;
}

Fixed::Fixed (const float value) {
    nbr = roundf(value * 256);
    // std::cout << "Float constructor called for value: " << value << std::endl;
}

float Fixed::toFloat() const {
    return (float)nbr / 256;
}

int Fixed::toInt() const {
    return (int)nbr / 256;
}

Fixed &Fixed::operator = (const Fixed& fix) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fix) {
        return *this;
    }
    nbr = fix.getRawBits();
    return *this;
}

//___________________________________________________________________________

bool Fixed::operator > (const Fixed& obj) const {
    return (nbr > obj.nbr);
}

bool Fixed::operator < (const Fixed& obj) const {
    return (nbr < obj.nbr);
}

bool Fixed::operator >= (const Fixed& obj) const {
    return (nbr >= obj.nbr);
}

bool Fixed::operator <= (const Fixed& obj) const {
    return (nbr <= obj.nbr);
}

bool Fixed::operator == (const Fixed& obj) const {
    return (nbr == obj.nbr);
}

bool Fixed::operator != (const Fixed& obj) const {
    return (nbr != obj.nbr);
}

Fixed Fixed::operator + (const Fixed& x) const {
    // std::cout << nbr << " + " << x.nbr << " = " << nbr + x.nbr << std::endl;
    // Fixed result = ;
    return createFixed(nbr + x.nbr);
}

Fixed Fixed::operator - (const Fixed& x) const {
    // return Fixed(nbr - x.nbr);
    return createFixed(nbr - x.nbr);
}

Fixed Fixed::operator * (const Fixed& x) const {
    // return Fixed(nbr * x.nbr);
    // std::cout << nbr << " * " << x.nbr << " = " << nbr * x.nbr << std::endl;
    return createFixed((nbr * x.nbr)/256);
}

Fixed Fixed::operator / (const Fixed& x) const {
    if (x.nbr == 0) {
        return nbr;
    }
    return createFixed((nbr * 256)/ x.nbr);
}
// pre - increment overload
Fixed& Fixed::operator ++ () {
    nbr++;
    return *this;
}
//post - increment overload
Fixed Fixed::operator ++ (int) {
    Fixed tmp;
    tmp.nbr = nbr++;
    return tmp;
}

// pre - decrement overload
Fixed& Fixed::operator -- () {
    nbr--;
    return *this;
}
//post - decrement overload
Fixed Fixed::operator -- (int) {
    Fixed tmp;
    tmp.nbr = nbr--;
    return tmp;
}
    
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}
    
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}

Fixed Fixed::createFixed(int nbr) {
    Fixed result;
    result.setRawBits(nbr);
    return result;
}
//___________________________________________________________________________

std::ostream& operator << (std::ostream& outstream, const Fixed& fixed) {
    outstream << fixed.toFloat();
    // outstream << " huy";
    return outstream;
}
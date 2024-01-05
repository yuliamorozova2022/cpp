/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:56:05 by ymorozov          #+#    #+#             */
/*   Updated: 2023/12/14 13:18:03 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

/* 
The Orthodox Canonical Class Form
    A default constructor: used internally to initialize objects and data members when no other value is available.
    A copy constructor: used in the implementation of call-by-value parameters.
    An assignment operator: used to assign one value to another.
    A destructor: Invoked when an object is deleted.
 */

class Fixed {
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& copy);
    ~Fixed();
    
    Fixed& operator = (const Fixed& fix);
    
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
    
    bool operator > (const Fixed& obj) const;
    bool operator < (const Fixed& obj) const;
    bool operator >= (const Fixed& obj) const;
    bool operator <= (const Fixed& obj) const;
    bool operator == (const Fixed& obj) const;
    bool operator != (const Fixed& obj) const;
    
    Fixed operator + (const Fixed& x) const;
    Fixed operator - (const Fixed& x) const;
    Fixed operator * (const Fixed& x) const;
    Fixed operator / (const Fixed& x) const;

    Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);
    static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int nbr;
    static const int fr_bit = 8;
    static Fixed createFixed(int nbr);
};

std::ostream& operator << (std::ostream& outstream, const Fixed& fixed);

#endif
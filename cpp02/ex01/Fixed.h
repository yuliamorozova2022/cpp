/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:56:05 by ymorozov          #+#    #+#             */
/*   Updated: 2023/11/16 20:31:19 by yuliamorozo      ###   ########.fr       */
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

private:
    int nbr;
    static const int fr_bit = 8;
};
    std::ostream& operator << (std::ostream& outstream, const Fixed& fixed);

#endif
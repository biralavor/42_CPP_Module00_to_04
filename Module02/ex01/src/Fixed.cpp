/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:27 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/11 13:54:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
    : _fixedPointValue(0) // Initialize _fixedPointValue to zero
{
    std::cout << "Fixed constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Fixed class object was destroyed" << std::endl;
}

Fixed::Fixed(const int rawAsInteger)
{
    std::cout << "Integer constructor called" << std::endl;
    this->_fixedPointValue = rawAsInteger << this->_raw;
}

Fixed::Fixed(const float rawAsFloat)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(rawAsFloat * (1 << this->_raw));
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> this->_raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << this->_raw);
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rightSideValue)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rightSideValue) // Check for self-assignment
        this->_fixedPointValue = rightSideValue.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rightSideValue) const
{
    std::cout << "Copy addition operator called" << std::endl;
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rightSideValue.getRawBits());
    return result;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &output, Fixed const &nbr)
{
    output << nbr.toFloat();
    return output;
}

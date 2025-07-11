/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:27 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/11 11:53:37 by umeneses         ###   ########.fr       */
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

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rightSideValue)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rightSideValue) // Check for self-assignment
        this->_fixedPointValue = rightSideValue.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rightSideValue) const
{
    std::cout << "Addition operator called" << std::endl;
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

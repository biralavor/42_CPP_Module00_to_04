/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:27 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 12:31:58 by umeneses         ###   ########.fr       */
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
    : _fixedPointValue(rawAsInteger << this->_raw)
{
    std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float rawAsFloat)
    : _fixedPointValue(roundf(rawAsFloat * (1 << this->_raw)))
{
    std::cout << "Float constructor called" << std::endl;
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

Fixed Fixed::operator+(Fixed const &rightSideValue) const
{
    std::cout << "Copy addition operator called" << std::endl;
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rightSideValue.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const &rightSideValue) const
{
    std::cout << "Copy subtraction operator called" << std::endl;
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rightSideValue.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const &rightSideValue) const
{
    std::cout << "Copy multiplication operator called" << std::endl;
    return Fixed(this->toFloat() * rightSideValue.toFloat());
}

Fixed Fixed::operator/(Fixed const &rightSideValue) const
{
    std::cout << "Copy division operator called" << std::endl;
    if (rightSideValue.getRawBits() == 0)
        return Fixed(0);
    Fixed result;
    result.setRawBits((long long)(this->_fixedPointValue << this->_raw)
        / rightSideValue.getRawBits());
    return result;
}

Fixed &Fixed::operator=(Fixed const &rightSideValue)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rightSideValue) // Check for self-assignment
        this->_fixedPointValue = rightSideValue.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const &rightSideValue) const
{
    std::cout << "Greater than operator called" << std::endl;
    return this->_fixedPointValue > rightSideValue.getRawBits();
}

bool Fixed::operator<(Fixed const &rightSideValue) const
{
    std::cout << "Less than operator called" << std::endl;
    return this->_fixedPointValue < rightSideValue.getRawBits();
}

bool Fixed::operator>=(Fixed const &rightSideValue) const
{
    std::cout << "Greater than or equal to operator called" << std::endl;
    return this->_fixedPointValue >= rightSideValue.getRawBits();
}

bool Fixed::operator<=(Fixed const &rightSideValue) const
{
    std::cout << "Less than or equal to operator called" << std::endl;
    return this->_fixedPointValue <= rightSideValue.getRawBits();
}

bool Fixed::operator!=(Fixed const &rightSideValue) const
{
    std::cout << "Not equal operator called" << std::endl;
    return this->_fixedPointValue != rightSideValue.getRawBits();
}

bool Fixed::operator==(Fixed const &rightSideValue) const
{
    std::cout << "Equality operator called" << std::endl;
    return this->_fixedPointValue == rightSideValue.getRawBits();
}

Fixed &Fixed::operator++(void)
{
    std::cout << "Pre-increment operator called" << std::endl;
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    std::cout << "Post-increment operator called" << std::endl;
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--(void)
{
    std::cout << "Pre-decrement operator called" << std::endl;
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    std::cout << "Post-decrement operator called" << std::endl;
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed const &Fixed::max(Fixed const &nbrA, Fixed const &nbrB)
{
    std::cout << "Max function called for consts references" << std::endl;
    return (nbrA.getRawBits() > nbrB.getRawBits()) ? nbrA : nbrB;
}

Fixed &Fixed::max(Fixed &nbrA, Fixed &nbrB)
{
    std::cout << "Max function called" << std::endl;
    return (nbrA.getRawBits() > nbrB.getRawBits()) ? nbrA : nbrB;
}

Fixed const &Fixed::min(Fixed const &nbrA, Fixed const &nbrB)
{
    std::cout << "Min function called for consts references" << std::endl;
    return (nbrA.getRawBits() < nbrB.getRawBits()) ? nbrA : nbrB;
}

Fixed &Fixed::min(Fixed &nbrA, Fixed &nbrB)
{
    std::cout << "Min function called" << std::endl;
    return (nbrA.getRawBits() < nbrB.getRawBits()) ? nbrA : nbrB;
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

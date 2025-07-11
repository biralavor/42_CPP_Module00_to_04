/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/11 19:20:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    int _fixedPointValue;
    static const int _raw = 8;

public:
    /**
     * @brief Construct a new Fixed object.
     * This constructor initializes the fixed-point value to zero.
     * It is the default constructor for the Fixed class.
     */
    Fixed(void);

    /**
     * @brief Destroy the Fixed object.
     * This destructor is called when a Fixed object goes out of scope
     * or is deleted.
     */
    ~Fixed(void);
    
    /**
     * @brief Integer constructor for Fixed class initialization
     * with an integer value.
     * @param rawAsInteger integer value to initialize the Fixed object
     */
    Fixed(const int rawAsInteger);

    /**
     * @brief Float constructor for Fixed class initialization
     * with a float-point value.
     * @param rawAsFloat float-point value to initialize the Fixed object
     */
    Fixed(const float rawAsFloat);

    /**
     * @brief Copy constructor for Fixed class.
     * This constructor creates a new Fixed object as a copy of an existing one.
     */
    Fixed(Fixed const &src);
    
    /**
     * @brief Addition operator for Fixed class.
     * This operator allows the addition of two Fixed objects.
     * @param rightSideValue The Fixed object to add to the current object.
     * @return A new Fixed object that is the sum of the two.
     */
    Fixed operator+(Fixed const &rightSideValue) const;

    /**
     * @brief Subtraction operator for Fixed class.
     * This operator allows the subtraction of one Fixed object from another.
     * @param rightSideValue The Fixed object to subtract from the current object.
     * @return A new Fixed object that is the difference of the two.
     */
    Fixed operator-(Fixed const &rightSideValue) const;

    /**
     * @brief Multiplication operator for Fixed class.
     * This operator allows the multiplication of two Fixed objects.
     * @param rightSideValue The Fixed object to multiply with the current object.
     * @return A new Fixed object that is the product of the two.
     */
    Fixed operator*(Fixed const &rightSideValue) const;

    /**
     * @brief Division operator for Fixed class.
     * This operator allows the division of one Fixed object by another.
     * @param rightSideValue The Fixed object to divide the current object by.
     * @return A new Fixed object that is the quotient of the two.
     */
    Fixed operator/(Fixed const &rightSideValue) const;

    /**
     * @brief Assignment operator for Fixed class.
     * This operator allows one Fixed object to be assigned the value of another.
     * @param rightSideValue The Fixed object to copy from.
     * @return A reference to the current object.
     */
    Fixed &operator=(Fixed const &rightSideValue);

    /**
     * @brief Pre-increment operator for Fixed class.
     * This operator increments the current object by one and returns
     * the incremented value.
     * @return A reference to the incremented Fixed object.
     */
    bool operator>(Fixed const &rightSideValue) const;
    
    /**
     * @brief Post-increment operator for Fixed class.
     * This operator increments the current object by one and returns
     * the original value before incrementing.
     * @return A Fixed object that was the value before incrementing.
     */
    bool operator<(Fixed const &rightSideValue) const;
    
    /**
     * @brief Greater than or equal to operator for Fixed class.
     * This operator checks if the current object is greater than or equal
     * to another Fixed object.
     * @param rightSideValue The Fixed object to compare with the current object.
     * @return A boolean indicating whether the current object is
     * greater than or equal to the other.
     */
    bool operator>=(Fixed const &rightSideValue) const;

    /**
     * @brief Less than or equal to operator for Fixed class.
     * This operator checks if the current object is less than or equal
     * to another Fixed object.
     * @param rightSideValue The Fixed object to compare with the current object.
     * @return A boolean indicating whether the current object is
     * less than or equal to the other.
     */
    bool operator<=(Fixed const &rightSideValue) const;

    /**
     * @brief Equality operator for Fixed class
     * This operator checks if two Fixed objects are equal.
     * @param rightSideValue The Fixed object to compare with the current object.
     * @return A boolean indicating whether the two objects are equal.
     */
    bool operator==(Fixed const &rightSideValue) const;

    /**
     * @brief Not equal operator for Fixed class
     * This operator checks if two Fixed objects are not equal.
     * @param rightSideValue The Fixed object to compare with the current object.
     * @return A boolean indicating whether the two objects are not equal.
     */
    bool operator!=(Fixed const &rightSideValue) const;
    
    /**
     * @brief Pre-increment operator for Fixed class.
     * This operator increments the current object by one and returns
     * the incremented value.
     * @return A reference to the incremented Fixed object.
     */
    Fixed &operator++(void);
    
    /**
     * @brief Post-increment operator for Fixed class.
     * This operator increments the current object by one and returns
     * the original value before incrementing.
     * @return A Fixed object that was the value before incrementing.
     */
    Fixed &operator--(void);
    
    /**
     * @brief Post-decrement operator for Fixed class.
     * This operator decrements the current object by one and returns
     * the original value before decrementing.
     * @return A Fixed object that was the value before decrementing.
     */
    Fixed operator++(int);
    
    /**
     * @brief Post-decrement operator for Fixed class.
     * This operator decrements the current object by one and returns
     * the original value before decrementing.
     * @return A Fixed object that was the value before decrementing.
     */
    Fixed operator--(int);
    
    /**
     * @brief Get the maximum of two Fixed objects for const references.
     * This static method returns the greater of two Fixed objects.
     * @param nbrA The first Fixed-pointer-number object.
     * @param nbrB The second Fixed-pointer-number object.
     * @return The Fixed object with the greater value.
     */
    static Fixed const &max(Fixed const &nbrA, Fixed const &nbrB);
    
    /**
     * @brief Get the maximum of two Fixed objects.
     * This static method returns the greater of two Fixed objects.
     * @param nbrA The first Fixed-pointer-number object.
     * @param nbrB The second Fixed-pointer-number object.
     * @return The Fixed object with the greater value.
     */
    static Fixed &max(Fixed &nbrA, Fixed &nbrB);

    /**
     * @brief Get the minimum of two Fixed objects for const references.
     * This static method returns the lesser of two Fixed objects.
     * @param nbrA The first Fixed-pointer-number object.
     * @param nbrB The second Fixed-pointer-number object.
     * @return The Fixed object with the lesser value.
     */
    static Fixed const &min(Fixed const &nbrA, Fixed const &nbrB);

    /**
     * @brief Get the minimum of two Fixed objects.
     * This static method returns the lesser of two Fixed objects.
     * @param nbrA The first Fixed-pointer-number object.
     * @param nbrB The second Fixed-pointer-number object.
     * @return The Fixed object with the lesser value.
     */
    static Fixed &min(Fixed &nbrA, Fixed &nbrB);
    
    /**
     * @brief Get the raw bits of the fixed-point value
     * This method retrieves the raw bits of the fixed-point value.
     * @return The raw bits of the fixed-point value.
     */
    int getRawBits(void) const;
    
    /**
     * @brief Set the raw bits of the fixed-point value
     * This method sets the raw bits of the fixed-point value.
     * @param raw The new raw bits value to set.
     */
    void setRawBits(int const raw);

    /**
     * @brief Converts the Fixed object to an Integer value
     * @return `int` Integer value of the Fixed object
     */
    int toInt(void) const;
    
    /**
     * @brief Converts the Fixed object to a Float value
     * @return `float` Float value of the Fixed object
     */
    float toFloat(void) const;
};

/**
 * @brief An overload global function operator which inserts
 * a floating-point representation of the fixed-point number `nbr`
 * into the `output` stream object.
 * @param output output stream object
 * @param nbr fixed-point number to be inserted
 * @return `std::ostream` a reference to the stream to allows 
 * multiple operations together
 * (like `std::cout "a value = " << a std::endl;`)
 */
std::ostream &operator<<(std::ostream &output, Fixed const &nbr);

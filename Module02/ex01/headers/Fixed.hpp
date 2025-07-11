/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/11 13:57:27 by umeneses         ###   ########.fr       */
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
     * @brief Construct a new Fixed object
     * This constructor initializes the fixed-point value to zero.
     * It is the default constructor for the Fixed class.
     */
    Fixed(void);

    /**
     * @brief Destroy the Fixed object
     * This destructor is called when a Fixed object goes out of scope or is deleted.
     */
    ~Fixed(void);
    
    /**
     * @brief Integer constructor for Fixed class initialization
     * with an integer value
     * @param rawAsInteger integer value to initialize the Fixed object
     */
    Fixed(const int rawAsInteger);

    /**
     * @brief Float constructor for Fixed class initialization
     * with a float-point value
     * @param rawAsFloat float-point value to initialize the Fixed object
     */
    Fixed(const float rawAsFloat);

    /**
     * @brief Copy constructor for Fixed class
     * This constructor creates a new Fixed object as a copy of an existing one.
     */
    Fixed(Fixed const &src);
    
    /**
     * @brief Assignment operator for Fixed class
     * This operator allows one Fixed object to be assigned the value of another.
     * @param rightSideValue The Fixed object to copy from.
     * @return A reference to the current object.
     */
    Fixed &operator=(Fixed const &rightSideValue);
    
    /**
     * @brief Addition operator for Fixed class
     * This operator allows the addition of two Fixed objects.
     * @param rightSideValue The Fixed object to add to the current object.
     * @return A new Fixed object that is the sum of the two.
     */
    Fixed operator+(Fixed const &rightSideValue) const;

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

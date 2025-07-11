/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:41:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/11 11:58:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

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

};

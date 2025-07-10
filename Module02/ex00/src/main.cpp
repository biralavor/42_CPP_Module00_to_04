/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:42:06 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/09 21:27:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed one;
    Fixed two(one);
    Fixed three;
    
    three = two;
    
    std::cout << "one: " << one.getRawBits() << std::endl;
    std::cout << "two: " << two.getRawBits() << std::endl;
    std::cout << "three: " << three.getRawBits() << std::endl;
    
    // one.setRawBits(42);
    // std::cout << "\n>>>>>>>>>>>>\nAfter setting one to 42:" << std::endl;
    // std::cout << "one: " << one.getRawBits() << std::endl;
    // std::cout << "two: " << two.getRawBits() << std::endl;
    // std::cout << "three: " << three.getRawBits() << std::endl;

    return 0;
}

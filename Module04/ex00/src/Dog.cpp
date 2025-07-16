/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:02:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 19:05:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Default Dog")
{
	std::cout
	<< "Dog default constructor called."
	<< std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout
	<< "Dog parameterized constructor called with type: "
	<< type << std::endl;
}

Dog::~Dog(void)
{
	std::cout
	<< "Dog destructor called for type: " << type
	<< std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout
	<< "Dog copy constructor called for type: "
	<< src.type << std::endl;
}

Dog &Dog::operator=(Dog const &rightSide)
{
	std::cout
	<< "Dog assignment operator called for type: "
	<< rightSide.type << std::endl;
	if (this != &rightSide) {
		Animal::operator=(rightSide); // Call base class assignment operator
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "BARK! BARK!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:15:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 19:17:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Unknown") {
	std::cout
	<< "Animal default constructor called."
	<< std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout
	<< "Animal parameterized constructor called with type: "
	<< type << std::endl;
}

Animal::~Animal(void)
{
	std::cout
	<< "Animal destructor called for type: " << type
	<< std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout
	<< "Animal copy constructor called for type: "
	<< src.type << std::endl;
	*this = src; // Use assignment operator to copy
}

Animal &Animal::operator=(Animal const &rightSide)
{
	std::cout
	<< "Animal assignment operator called for type: "
	<< rightSide.type << std::endl;
	if (this != &rightSide) {
		type = rightSide.type; // Copy the type
	}
	return *this;
}

void Animal::setType(const std::string newType)
{
	this->type = newType;
}

std::string Animal::getType(void) const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal makes a sound." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:15:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:37:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: _className("Animal"),
	_type("Weird Animal")
{
	_printer.constructorTitlePrinter(_className, _type);
}

Animal::Animal(std::string type)
	: _className("Animal"),
	_type("Weird Animal")
{
	_printer.constructorTitlePrinter(_className, type);
}

Animal::~Animal(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

Animal::Animal(Animal const &src)
	: _className(src._className),
	_type(src._type)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

Animal &Animal::operator=(Animal const &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
	{
		_type = rightSide._type;
	}
	return *this;
}

void Animal::setType(const std::string newType)
{
	this->_type = newType;
}

std::string Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout
	<< GRAY
	<< " __     ," << std::endl
	<< "(__).o.@c" << std::endl
	<< " /  |  \\  says "
	<< "::no::hearable::sound::" << std::endl
	<< YELLOW << this->_type << RESET
	<< std::endl;
}
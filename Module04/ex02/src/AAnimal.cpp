/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:21:05 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 16:59:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
	: _className("AAnimal"),
	_type("Weird AAnimal")
{
	_printer.constructorTitlePrinter(_className, _type);
}

AAnimal::AAnimal(std::string type)
	: _className("AAnimal"),
	_type(type)
{
	_printer.constructorTitlePrinter(_className, type);
}

AAnimal::~AAnimal(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

AAnimal::AAnimal(AAnimal const &src)
	: _className(src._className),
	_type(src._type)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

AAnimal &AAnimal::operator=(AAnimal const &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
	{
		_type = rightSide._type;
	}
	return *this;
}

void AAnimal::setType(const std::string newType)
{
	this->_type = newType;
}

std::string AAnimal::getType(void) const
{
	return _type;
}

void AAnimal::makeSound(void) const
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:18:39 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:36:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: _className("WrongAnimal"),
	_type("Weird WrongAnimal")
{
	_printer.constructorTitlePrinter(_className, _type);

}

WrongAnimal::WrongAnimal(std::string type)
	: _className("WrongAnimal"),
	_type("Weird WrongAnimal")
{
	_printer.constructorTitlePrinter(_className, type);
}

WrongAnimal::~WrongAnimal(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
	: _className(src._className),
	_type(src._type)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
		_type = rightSide._type;
	return *this;
}

void WrongAnimal::setType(const std::string newType)
{
	this->_type = newType;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
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

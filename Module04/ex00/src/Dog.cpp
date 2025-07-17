/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:02:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 15:29:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _className("Dog")
{
	_printer.constructorTitlePrinter(_className, "Weird Dog");
}

Dog::Dog(std::string type) : Animal(type), _className("Dog")
{
	_printer.constructorTitlePrinter(_className, type);
}

Dog::~Dog(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

Dog::Dog(Dog const &src)
	: _className(src._className)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

Dog &Dog::operator=(Dog const &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
	{
		_type = rightSide._type;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	_printer.dogMakeSoundPrinter(_type);
}

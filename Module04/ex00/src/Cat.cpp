/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:02:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 15:28:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _className("Cat")
{
	_printer.constructorTitlePrinter(_className, "Weird Cat");
}

Cat::Cat(std::string type) : Animal(type), _className("Cat")
{
	_printer.constructorTitlePrinter(_className, type);
}

Cat::~Cat(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

Cat::Cat(Cat const &src)
	: _className(src._className)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

Cat &Cat::operator=(Cat const &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
	{
		_type = rightSide._type;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	_printer.catMakeSoundPrinter(_type);
}

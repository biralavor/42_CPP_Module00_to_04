/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:02:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 19:55:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _className("Dog")
{
	_myBrain = new Brain();
	_printer.constructorTitlePrinter(_className, "Weird Dog");
}

Dog::Dog(std::string type) : Animal(type), _className("Dog")
{
	_myBrain = new Brain();
	_printer.constructorTitlePrinter(_className, type);
}

Dog::~Dog(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

Dog::Dog(Dog const &src)
	: _className(src._className)
{
	_myBrain = new Brain(*src._myBrain);
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

Dog &Dog::operator=(Dog const &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
	{
		_type = rightSide._type;
		delete _myBrain;
		_myBrain = new Brain(*rightSide._myBrain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout
	<< GREEN
	<< "   / \\__" << std::endl
	<< "  (    @\\___" << std::endl
	<< "  /         O" << std::endl
	<< " /   (_____/" << std::endl
	<< "/_____/   U   says " << YELLOW << "BARK! BARK!" << std::endl
	<< this->_type << RESET
	<< std::endl;
}

Brain *Dog::getBrain(void) const
{
	return _myBrain;
}
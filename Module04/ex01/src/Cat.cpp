/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:02:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 11:31:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _className("Cat")
{
	_myBrain = new Brain();
	_printer.constructorTitlePrinter(_className, "Weird Cat");
}

Cat::Cat(std::string type) : Animal(type), _className("Cat")
{
	_myBrain = new Brain();
	_printer.constructorTitlePrinter(_className, type);
}

Cat::~Cat(void)
{
	_printer.destructorTitlePrinter(_className, _type);
	delete _myBrain;
}

Cat::Cat(Cat const &src) : Animal(src._type), _className(src._className)
{
	_myBrain = new Brain(*src._myBrain);
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

Cat &Cat::operator=(Cat const &rightSide)
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

void Cat::makeSound(void) const
{
	std::cout
	<< GREEN
	<< " _._     _,-'""`-._" << std::endl
	<< "(,-.`._,'(       |\\`-/|" << std::endl
	<< "    `-.-' \\ )-`( , o o)" << std::endl
	<< "          `-    \\`_`\"'-\" says "
	<< YELLOW << "MEEOOOOW!!" << std::endl
	<< this->_type << RESET
	<< std::endl;
}

Brain *Cat::getBrain(void) const
{
	return _myBrain;
}
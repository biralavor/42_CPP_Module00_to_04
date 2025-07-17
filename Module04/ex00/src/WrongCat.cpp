/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:37:04 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:36:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : _className("WrongCat")
{
	_printer.constructorTitlePrinter(_className, _type);
}

WrongCat::WrongCat(std::string type) : _className("WrongCat")
{
	_printer.constructorTitlePrinter(_className, type);
}

WrongCat::~WrongCat(void)
{
	_printer.destructorTitlePrinter(_className, _type);
}

WrongCat::WrongCat(const WrongCat &src)
	: _className(src._className)
{
	_printer.copyConstructorPrinter(_className, src._type);
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &rightSide)
{
	_printer.operatorPrinter(_className, rightSide._type);
	if (this != &rightSide)
		_type = rightSide._type;
	return *this;
}

void WrongCat::makeSound(void) const
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

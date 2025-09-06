/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:33:48 by umeneses          #+#    #+#             */
/*   Updated: 2025/09/06 19:16:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	this->_convertTypes[0] = "int";
	this->_convertTypes[1] = "char";
	this->_convertTypes[2] = "float";
	this->_convertTypes[3] = "double";
	std::cout
	<< "\e[35m"
	<< "Possible TYPES to be converted are:"
	<< "\e[0m" << std::endl;
	for (int idx = 0; idx < POSSIBLE_TYPES; idx++)
	{
		std::cout
		<< "\e[36m"
		<< "- " << this-> _convertTypes[idx]
		<< "\e[0m" << std::endl;
	}
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rightSide)
{
	return *this;
}

bool isInt(const std::string &literal)
{
	
}

bool isChar(const std::string &literal)
{

}

bool isFloat(const std::string &literal)
{
	
}

bool isDouble(const std::string &literal)
{
	
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error. String is empty." << std::endl;
		return ;
	}
	
	PtrToMember typeValidation[] = {isInt, isChar, isFloat, isDouble};
	for (int idx = 0; idx < POSSIBLE_TYPES; idx++)
	{
		if (typeValidation[idx](literal))
		{
			std::cout
			<< "Type to be converted: "
			<< typeValidation[idx]
			<< std::endl;
			break;
		}
	}
}

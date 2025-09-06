/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:40:36 by umeneses          #+#    #+#             */
/*   Updated: 2025/09/06 19:07:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

#define POSSIBLE_TYPES 4

class ScalarConverter
{
	std::string _convertTypes[POSSIBLE_TYPES];
	
	typedef bool (*PtrToMember)(const std::string &literal);

	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rightSide);
	
	static bool isInt(const std::string &literal);
	static bool isChar(const std::string &literal);
	static bool isFloat(const std::string &literal);
	static bool isDouble(const std::string &literal);
	
	static void convertInt(const std::string &literal);
	static void convertChar(const std::string &literal);
	static void convertFloat(const std::string &literal);
	static void convertDouble(const std::string &literal);
	
public:
	static void convert(const std::string &literal);
};

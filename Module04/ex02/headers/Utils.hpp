/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:44:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:33:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

const std::string RESET = "\e[0m";
const std::string YELLOW = "\e[33m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";
const std::string BLUE = "\e[34m";
const std::string GRAY = "\e[90m";

class Utils
{
public:
	void constructorTitlePrinter(std::string type,
		std::string objectName) const;
	void statusConstructorPrinter(std::string type,
		int value) const;
	void destructorTitlePrinter(std::string type,
		std::string objectName) const;
	void copyConstructorPrinter(std::string type,
		std::string objectName) const;
	void operatorPrinter(std::string _className,
		std::string type) const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:25:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 16:29:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void Utils::constructorTitlePrinter(std::string type, std::string objectName) const
{
    std::cout
    << ":: " << type << " created: [" << YELLOW << objectName << RESET << "]"
    << std::endl;
}

void Utils::destructorTitlePrinter(std::string type, std::string objectName) const
{
    std::cout
	<< RED << "ᛝᛝᛝ " << type << " " << YELLOW << objectName
	<< RED <<" destroyed. ᛝᛝᛝ" << RESET
    << std::endl;
}

void Utils::statusConstructorPrinter(std::string type, int value) const
{
	std::cout
	<< "| " << std::setw(13) << type << " :::: " << "[" << value << "]\n"
	<< "---------------------------"
	<< std::endl;
}

void Utils::statusEmojizerPrinter(std::string type, int value) const
{
	std::string emoji;
	std::string emptySlot = "⬛";
	int idx = 0;
	
	if (type == "hit")
		emoji = "❤️ ";
	else if (type == "energy")
		emoji = "⚡️";
	else if (type == "attack")
		emoji = "💥";
	else
		emoji = "❓";
	std::cout
	<< "| " << std::setw(7) << type << " :::: " << "[";
	while(idx++ < value)
		std::cout << emoji;
	while(idx++ <= 10)
		std::cout << emptySlot;
	std::cout << "]"
	<< std::endl;
}

void Utils::roundTitlePrinter(std::string title) const
{
    int width = 30;
    char paddingChar = ':';
    int paddingSize = (width - title.length()) + 2;

    std::cout << BLUE << std::string(width * 2, paddingChar) << std::endl;
    std::cout << " " << std::string(paddingSize, paddingChar)
	<< " " + title + " " << std::string(paddingSize, paddingChar) << std::endl;
    std::cout << std::string(width * 2, paddingChar)
	<< RESET << std::endl;
}

void Utils::zeroPointsPrinter(std::string classType, std::string pointsType,
    std::string objectName) const
{
    std::cout << RED << classType << " " << YELLOW << objectName;
    if (pointsType == "hit")
    {
        std::cout
        << RED << " is " << "dead!\n" << RESET
		<< std::endl;
    }
    else if (pointsType == "energy")
    {
        std::cout
		<< " has no energy left to repair! In other words: it is "
		<< RED << "dead!\n" << RESET
		<< std::endl;
    }
}

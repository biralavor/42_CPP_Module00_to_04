/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:49:45 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/20 15:56:53 by umeneses         ###   ########.fr       */
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

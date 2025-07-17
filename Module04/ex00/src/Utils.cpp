/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:45:13 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 15:27:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void Utils::constructorTitlePrinter(std::string _className,
	std::string type) const
{
	std::cout
    << ":: " << _className << " created: [" << YELLOW
	<< type << RESET << "]"
    << std::endl;
}

void Utils::destructorTitlePrinter(std::string _className,
	std::string type) const
{
    std::cout
	<< RED << "ᛝᛝᛝ " << _className << " " << YELLOW << type
	<< RED <<" destroyed. ᛝᛝᛝ" << RESET
    << std::endl;
}

void Utils::statusConstructorPrinter(std::string type,
	int value) const
{
	std::cout
	<< "| " << std::setw(13) << type << " :::: " << "[" << value << "]\n"
	<< "---------------------------"
	<< std::endl;
}

void Utils::animalMakeSoundPrinter(std::string type) const
{
	std::cout
	<< GREEN
	<< " __     ," << std::endl
	<< "(__).o.@c" << std::endl
	<< " /  |  \\  says: " << YELLOW << ":::!!!:::" << std::endl
	<< type << RESET
	<< std::endl;
}

void Utils::dogMakeSoundPrinter(std::string type) const
{
	std::cout
	<< GREEN
	<< "   / \\__" << std::endl
	<< "  (    @\\___" << std::endl
	<< "  /         O" << std::endl
	<< " /   (_____/" << std::endl
	<< "/_____/   U   says: " << YELLOW << "BARK! BARK!" << std::endl
	<< type << RESET
	<< std::endl;
}

void Utils::catMakeSoundPrinter(std::string type) const
{
	std::cout
	<< GREEN
	<< " _._     _,-'""`-._" << std::endl
	<< "(,-.`._,'(       |\\`-/|" << std::endl
	<< "    `-.-' \\ )-`( , o o)" << std::endl
	<< "          `-    \\`_`\"'-\" says: "
	<< YELLOW << "MEEOOOOW!!" << std::endl
	<< type << RESET
	<< std::endl;
}

void Utils::copyConstructorPrinter(std::string _className,
	std::string type) const
{
	std::cout
	<< GREEN << _className << RESET << " Copy constructor for type: "
	<< YELLOW << type << RESET << std::endl;
}

void Utils::operatorPrinter(std::string _className,
	std::string type) const
{
	std::cout
	<< GREEN << _className << RESET << " assignment operator for type: "
	<< YELLOW << type << RESET << std::endl;
}
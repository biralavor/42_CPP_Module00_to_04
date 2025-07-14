/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:31:24 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 13:29:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << ">> ScavTrap created: [" << YELLOW
	<< name << RESET << "]" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ᛝᛝᛝ " << "ScavTrap " << YELLOW << this->getName()
	<< RED <<" destroyed. ᛝᛝᛝ" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << YELLOW << this->getName() << RESET
	<< " is now in Gate Keeper mode!" << std::endl;
}
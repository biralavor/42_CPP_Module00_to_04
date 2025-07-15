/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:31:24 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 22:03:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_classType = "ScavTrap";
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

ScavTrap::~ScavTrap()
{
	_printer.destructorTitlePrinter(_classType, _name);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << YELLOW << this->getName() << RESET
	<< " is now in Gate Keeper mode!" << std::endl;
}
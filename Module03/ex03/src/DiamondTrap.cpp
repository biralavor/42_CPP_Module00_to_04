/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:52:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + SUFIX),
    ScavTrap(name + SUFIX),
    FragTrap(name + SUFIX),
    _name(name)
{
    _classType = "DiamondTrap";
    _printer.constructorTitlePrinter(_classType, _name);
    _printer.statusConstructorPrinter("hit points", _hitPoints);
    _printer.statusConstructorPrinter("energy points", _energyPoints);
    _printer.statusConstructorPrinter("attack damage", _attackDamage);
}

DiamondTrap::~DiamondTrap()
{
    _printer.destructorTitlePrinter(_classType, _name);
}

void DiamondTrap::whoAmI()
{
    this->_energyPoints--;
    std::cout
    << "I am " << YELLOW << _name << RESET
    << ", my ClapTrap name is " << YELLOW
    << ClapTrap::_name << RESET << std::endl;
}

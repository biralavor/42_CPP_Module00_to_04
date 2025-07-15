/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:52:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/15 00:52:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
    _classType = "DiamondTrap";
    this->setName(name);
    // _fragTrap.setName(_name + SUFIX);
    // _scavTrap.setName(_name + SUFIX);
    _printer.constructorTitlePrinter(_classType, _name);
    _printer.statusConstructorPrinter("hit points", _hitPoints);
    _printer.statusConstructorPrinter("energy points", _energyPoints);
    _printer.statusConstructorPrinter("attack damage", _attackDamage);

    // _fragTrap.setDiamondTrap(this);
    // _scavTrap.setDiamondTrap(this);
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
    << _fragTrap.getName() << RESET << std::endl;
}

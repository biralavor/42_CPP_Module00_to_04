/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:52:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/15 22:08:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + SUFFIX),
    ScavTrap(name + SUFFIX),
    FragTrap(name + SUFFIX),
    _name(name + SUFFIX)
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

DiamondTrap::DiamondTrap(DiamondTrap const &src)
    : ClapTrap(src),
    ScavTrap(src),
    FragTrap(src)
{
    std::cout << _classType << " copy constructor called for: "
              << YELLOW << _name << RESET << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rightSide)
{
    if (this != &rightSide)
    {
        std::string tempName = rightSide.getName();
        this->setName(tempName);
        this->setHitPoints(rightSide.getHitPoints());
        this->setEnergyPoints(rightSide.getEnergyPoints());
        this->setAttackDamage(rightSide.getAttackDamage());
    }
    std::cout << _classType << " assignment operator called for: "
              << YELLOW << _name << RESET << std::endl;
    return *this;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    this->_energyPoints--;
    std::cout
    << "I am " << YELLOW << _name << RESET
    << ", my ClapTrap name is " << YELLOW
    << ClapTrap::getName() << RESET << std::endl;
}

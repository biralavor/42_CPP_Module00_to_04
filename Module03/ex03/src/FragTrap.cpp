/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:49:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 14:28:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap("Default")
{
	_classType = "FragTrap";
	_maxHit = 100;
	_maxEnergy = 100;
	_maxDamage = 30;
	this->setHitPoints(_maxHit);
	this->setEnergyPoints(_maxEnergy);
	this->setAttackDamage(_maxDamage);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_classType = "FragTrap";
	_maxHit = 100;
	_maxEnergy = 100;
	_maxDamage = 30;
	this->setHitPoints(_maxHit);
	this->setEnergyPoints(_maxEnergy);
	this->setAttackDamage(_maxDamage);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

FragTrap::~FragTrap(void)
{
	_printer.destructorTitlePrinter(_classType, _name);
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout
	<< _classType << " copy constructor called for: "
	<< YELLOW << _name << RESET
	<< std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rightSide)
{
	if (this != &rightSide)
	{
		this->_name = rightSide._name;
		this->_hitPoints = rightSide._hitPoints;
		this->_energyPoints = rightSide._energyPoints;
		this->_attackDamage = rightSide._attackDamage;
		this->_maxHit = rightSide._maxHit;
		this->_maxEnergy = rightSide._maxEnergy;
		this->_maxDamage = rightSide._maxDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	this->_energyPoints--;
	std::cout << "🤜🤛 " << _classType << " "
	<< YELLOW << this->getName() << RESET
	<< " is requesting a high five! 🙌🙌🙌🙌🙌"
	<< std::endl;
}

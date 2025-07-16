/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:31:24 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 16:15:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap("Default")
{
	_classType = "ScavTrap";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_classType = "ScavTrap";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

ScavTrap::~ScavTrap(void)
{
	_printer.destructorTitlePrinter(_classType, _name);
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout
	<< _classType << " copy constructor called for: "
	<< YELLOW << _name << RESET
	<< std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rightSide)
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

void ScavTrap::guardGate()
{
	this->_energyPoints--;
	std::cout << "ScavTrap " << YELLOW << this->getName() << RESET
	<< " is now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout
		<< _classType << " " << YELLOW << _name << RESET << " attacks "
		<< YELLOW << target << RESET <<", causing [" << RED
		<< _attackDamage << RESET  << "] points of damage!"
		<< std::endl;
		_printer.statusEmojizerPrinter("hit", _hitPoints, _maxHit);
		_printer.statusEmojizerPrinter("energy", _energyPoints, _maxEnergy);
		_printer.statusEmojizerPrinter("attack", _attackDamage, _maxDamage);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
	else
		_printer.zeroPointsPrinter(_classType, "energy", _name);
}

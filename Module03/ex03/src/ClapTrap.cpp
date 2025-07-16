/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:41 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 15:39:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_classType = "ClapTrap";
	_maxHit = 10;
	_maxEnergy = 10;
	_maxDamage = 0;
	this->setHitPoints(_maxHit);
	this->setEnergyPoints(_maxEnergy);
	this->setAttackDamage(_maxDamage);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_classType = "ClapTrap";
	_maxHit = 10;
	_maxEnergy = 10;
	_maxDamage = 0;
	this->setHitPoints(_maxHit);
	this->setEnergyPoints(_maxEnergy);
	this->setAttackDamage(_maxDamage);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

ClapTrap::~ClapTrap(void)
{
	_printer.destructorTitlePrinter(_classType, _name);
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout
	<< _classType << " copy constructor called for: "
	<< YELLOW << _name << RESET
	<< std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightSide)
{
	std::cout
	<< _classType << " assignment operator called for: "
	<< YELLOW << _name << RESET
	<< std::endl;
	if (this != &rightSide)
	{
		_name = rightSide._name;
		_hitPoints = rightSide._hitPoints;
		_energyPoints = rightSide._energyPoints;
		_attackDamage = rightSide._attackDamage;
	}
	return *this;
}

void ClapTrap::setName(std::string &name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void ClapTrap::attack(const std::string &target)
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
	if (_energyPoints <= 0)
		_printer.zeroPointsPrinter(_classType, "energy", _name);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout
		<< _classType << " " << YELLOW << _name << RESET <<" takes ["
		<< RED << amount << RESET << "] points of damage!"
		<< std::endl;
		_printer.statusEmojizerPrinter("hit", _hitPoints, _maxHit);
		_printer.statusEmojizerPrinter("energy", _energyPoints, _maxEnergy);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
	if (_hitPoints <= 0)
		_printer.zeroPointsPrinter(_classType, "hit", _name);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 )
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout
		<< _classType << " " << YELLOW << _name << RESET
		<< " repairs itself for [" << GREEN << amount << RESET << "] points!"
		<< std::endl;
		_printer.statusEmojizerPrinter("hit", _hitPoints, _maxHit);
		_printer.statusEmojizerPrinter("energy", _energyPoints, _maxEnergy);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
	if (_energyPoints <= 0)
		_printer.zeroPointsPrinter(_classType, "energy", _name);
}

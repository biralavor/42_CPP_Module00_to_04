/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:41 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 19:04:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << ">> ClapTrap created: [" << _name << "]" << std::endl;
	statusConstructorPrinter("hit points", _hitPoints);
	statusConstructorPrinter("energy points", _energyPoints);
	statusConstructorPrinter("attack damage", _attackDamage);
}

ClapTrap::~ClapTrap()
{
	std::cout
	<< RED << "ᛝᛝᛝ " << "ClapTrap " << YELLOW << _name
	<< RED <<" destroyed. ᛝᛝᛝ" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
	: _name(src._name),
	  _hitPoints(src._hitPoints),
	  _energyPoints(src._energyPoints),
	  _attackDamage(src._attackDamage)
{
	std::cout
	<< "ClapTrap copy constructor called for: " << YELLOW << _name << RESET
	<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightSide)
{
	std::cout
	<< "ClapTrap assignment operator called for: " << YELLOW << _name << RESET
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

void ClapTrap::statusConstructorPrinter(std::string type, int value) const
{
	std::cout
	<< "| " << std::setw(13) << type << " :::: " << "[" << value << "]\n"
	<< "---------------------------"
	<< std::endl;
}

void ClapTrap::statusEmojizerPrinter(std::string type, int value) const
{
	std::string emoji;
	std::string emptySlot = "⬛";
	int idx = 0;
	
	if (type == "hit")
		emoji = "❤️ ";
	else if (type == "energy")
		emoji = "⚡️";
	else if (type == "attack")
		emoji = "💥";
	else
		emoji = "❓";
	std::cout
	<< "| " << std::setw(7) << type << " :::: " << "[";
	while(idx++ < value)
		std::cout << emoji;
	while(idx++ <= 10)
		std::cout << emptySlot;
	std::cout << "]"
	<< std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout
		<< "ClapTrap " << YELLOW << _name << RESET << " attacks "
		<< YELLOW << target << RESET <<", causing [" << RED
		<< _attackDamage << RESET  << "] points of damage!"
		<< std::endl;
		statusEmojizerPrinter("hit", _hitPoints);;
		statusEmojizerPrinter("energy", _energyPoints);
		statusEmojizerPrinter("attack", _attackDamage);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
	else
	{
		std::cout
		<< "ClapTrap " << YELLOW << _name << RESET
		<< " has no energy left to attack!\n"
		<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout
		<< "ClapTrap " << YELLOW << _name << RESET <<" takes ["
		<< RED << amount << RESET << "] points of damage!"
		<< std::endl;
		statusEmojizerPrinter("hit", _hitPoints);
		statusEmojizerPrinter("energy", _energyPoints);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 )
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout
		<< "ClapTrap " << YELLOW << _name << RESET
		<< " repairs itself for [" << GREEN << amount << RESET << "] points!"
		<< std::endl;
		statusEmojizerPrinter("hit", _hitPoints);
		statusEmojizerPrinter("energy", _energyPoints);
		std::cout << std::string(42,'/') << "\n" << std::endl;
	}
	else
	{
		std::cout
		<< "ClapTrap " << YELLOW << _name << RESET
		<< " has no energy left to repair!\n"
		<< std::endl;
	}
}

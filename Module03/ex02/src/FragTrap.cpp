/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:49:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 23:16:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

FragTrap::~FragTrap()
{
	_printer.destructorTitlePrinter(_classType, _name);
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "🤜🤛 " << _classType << " " << YELLOW << this->getName() << RESET
	<< " is requesting a high five! 🙌🙌🙌🙌🙌"
	<< std::endl;
}
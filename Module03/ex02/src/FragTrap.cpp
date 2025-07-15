/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:49:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 22:07:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_classType = "FragTrap";
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	_printer.constructorTitlePrinter(_classType, _name);
	_printer.statusConstructorPrinter("hit points", _hitPoints);
	_printer.statusConstructorPrinter("energy points", _energyPoints);
	_printer.statusConstructorPrinter("attack damage", _attackDamage);
}

FragTrap::~FragTrap()
{
	_printer.destructorTitlePrinter(_classType, _name);
}

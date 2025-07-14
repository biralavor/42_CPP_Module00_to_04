/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:49:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 14:42:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << ">> ClapTrap created: [" << YELLOW
	<< _name << RESET << "]" << std::endl;
	statusConstructorPrinter("hit points", _hitPoints);
	statusConstructorPrinter("energy points", _energyPoints);
	statusConstructorPrinter("attack damage", _attackDamage);
}

FragTrap::~FragTrap()
{
	std::cout
	<< RED << "ᛝᛝᛝ " << "FragTrap " << YELLOW << _name
	<< RED <<" destroyed. ᛝᛝᛝ" << RESET << std::endl;
}

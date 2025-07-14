/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:13:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 19:03:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

class ClapTrap
{
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

protected:
	std::string _classType;

public:
	Utils		_printer;

public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rightSide);
	void setName(std::string &name);
	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(int attackDamage);	
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:13:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 14:27:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

class ClapTrap
{
	std::string _classType;
protected:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	int			_maxHit;
	int			_maxEnergy;
	int			_maxDamage;

public:
	Utils		_printer;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	virtual ~ClapTrap(void);
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

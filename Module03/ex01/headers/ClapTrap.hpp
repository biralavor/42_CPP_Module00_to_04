/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:13:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 19:04:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

const std::string RESET = "\e[0m";
const std::string YELLOW = "\e[33m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";

class ClapTrap
{
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

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
	void statusConstructorPrinter(std::string type, int value) const;
	void statusEmojizerPrinter(std::string type, int value) const;
};

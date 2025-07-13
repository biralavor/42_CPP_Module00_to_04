/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:13:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 18:21:17 by umeneses         ###   ########.fr       */
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
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	~ClapTrap();
	void statusConstructorPrinter(std::string type, int value) const;
	void statusEmojizerPrinter(std::string type, int value) const;
};

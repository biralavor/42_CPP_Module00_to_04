/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:29:48 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 14:27:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	std::string _classType;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	virtual ~ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	ScavTrap &operator=(ScavTrap const &rightSide);

	void guardGate();
	virtual void attack(const std::string &target);
};

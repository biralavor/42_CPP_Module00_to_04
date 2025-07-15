/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:29:48 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 21:21:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &rightSide);

	void guardGate();
};

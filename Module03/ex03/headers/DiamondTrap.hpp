/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:51:03 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/15 00:38:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"

#define SUFIX "_clap_name"

class DiamondTrap : public FragTrap, public ScavTrap
{
    std::string _name;
    FragTrap    _fragTrap;
    ScavTrap    _scavTrap;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(DiamondTrap const &src);
    DiamondTrap &operator=(DiamondTrap const & rightSide);

    void whoAmI();
};

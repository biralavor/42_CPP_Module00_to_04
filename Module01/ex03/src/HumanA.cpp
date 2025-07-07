/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:28:19 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 14:56:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : name(name), weapon(weapon)
{
    // Initialization list used to avoid unnecessary copies
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout
    << this->name << " attacks with their "
    << weapon.getType()
    << std::endl;
}

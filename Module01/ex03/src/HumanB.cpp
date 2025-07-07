/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:15:29 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 15:52:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
    // if (weapon)
    //     delete weapon;
}

void HumanB::setWeapon(Weapon &weapon)
{
    if (this->weapon != NULL)
        delete this->weapon;
    this->weapon = &weapon;
}

void HumanB::attack(void) const
{
    std::cout
    << this->name << " attacks with their ";
    if(weapon)
        std::cout << weapon->getType();
    else
        std::cout << "words";
    std::cout << std::endl;
}
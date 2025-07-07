/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:26:30 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 15:39:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
    : type(type)
{
    // Initialization list used to avoid unnecessary copies
}

Weapon::~Weapon()
{
}

std::string Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}

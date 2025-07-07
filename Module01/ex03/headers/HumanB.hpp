/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:33 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 15:36:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
    std::string name;
    Weapon *weapon;
public:
    void attack(void) const;
    void setWeapon(Weapon &weapon);
    HumanB(std::string name);
    ~HumanB();
};

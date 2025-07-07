/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:54:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 15:37:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
    std::string name;
    Weapon &weapon;
public:
    void attack(void) const;
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
};

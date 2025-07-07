/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:54:22 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 14:43:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{
    std::string name;
    Weapon &weapon;
public:
    void attack();
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
};

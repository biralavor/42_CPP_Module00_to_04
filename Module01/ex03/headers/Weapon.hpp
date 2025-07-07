/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:51:04 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 15:39:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Weapon
{
    std::string type;
public:
    std::string getType(void) const;
    void setType(const std::string &type);
    Weapon(const std::string &type);
    ~Weapon();
};

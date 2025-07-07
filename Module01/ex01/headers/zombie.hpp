/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:58:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 11:43:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(void);
    ~Zombie(void);
    void announce(void) const;
    void setName(const std::string &name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

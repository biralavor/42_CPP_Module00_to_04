/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:58:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/06 20:58:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
    void announce(void);
public:
    Zombie(const std::string &name);
    ~Zombie(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

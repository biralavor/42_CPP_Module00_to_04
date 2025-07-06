/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:39:29 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/06 19:35:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
    this->name = name;
    this->announce();
}

Zombie::~Zombie(void)
{
    std::cout
    << this->name
    << ": is dead, again. Actually, it was never alive."
    << std::endl;
}

void Zombie::announce(void)
{
    std::cout
    << this->name
    << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie *newZombie(std::string name)
{
    Zombie *lazyZombie = new Zombie(name);
    return lazyZombie;
}

void randomChump(std::string name)
{
    Zombie fastZombie(name);
}

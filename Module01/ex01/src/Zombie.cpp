/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:39:29 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 13:49:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
    std::cout
    << this->name
    << ": is dead, again. Actually, it was never alive."
    << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}

void Zombie::announce(void) const
{
    std::cout
    << this->name
    << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie *newZombie(std::string name)
{
    Zombie *lazyZombie = new Zombie();
    lazyZombie->setName(name);
    lazyZombie->announce();
    return lazyZombie;
}

void randomChump(std::string name)
{
    Zombie fastZombie;
    fastZombie.setName(name);
    fastZombie.announce();
}

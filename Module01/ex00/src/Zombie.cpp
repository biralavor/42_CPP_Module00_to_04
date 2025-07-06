/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:39:29 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/06 18:42:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
    std::cout
    << this->getName()
    << ": is dead, again. Actually, it was never alive."
    << std::endl;
}

std::string Zombie::getName(void) const
{
    return this->name;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout
    << this->getName()
    << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
    Zombie *lazyZombie = new Zombie();
    lazyZombie->setName(name);
    lazyZombie->announce();
    return lazyZombie;
}

void Zombie::randomChump(std::string name)
{
    this->setName(name);
    this->announce();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:58:52 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 13:49:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

Zombie *zombieHorde(int n, std::string name)
{
    Zombie *hordeOfZombies = new Zombie[n];
    
    for (int idx = 0; idx < n; idx++)
    {
        hordeOfZombies[idx].setName(name);
    }
    return hordeOfZombies;
};

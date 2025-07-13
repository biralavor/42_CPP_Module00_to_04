/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:58 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 19:55:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap peanut("Peanut Butter");
	ClapTrap sandwich("Sandwich");

	ScavTrap scavTrap("Scavenger");
	
	// peanut.attack("Sandwich");
	// peanut.takeDamage(3);
	// peanut.beRepaired(3);

	// sandwich.attack("Peanut Butter");
	// sandwich.takeDamage(8);
	// sandwich.beRepaired(5);

	scavTrap.attack("Peanut Butter");
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(3);
	scavTrap.guardGate();


	return 0;
}
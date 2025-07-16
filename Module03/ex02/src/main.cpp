/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:58 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 15:52:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	ClapTrap peanut("Peanut Butter");

	peanut._printer.roundTitlePrinter("ROUND 01");
	peanut.attack("Sandwich");
	peanut.takeDamage(3);
	peanut.beRepaired(2);
	peanut.takeDamage(10);
	peanut.takeDamage(3);

	ClapTrap sandwich("Sandwich");
	
	sandwich._printer.roundTitlePrinter("ROUND 02");
	sandwich.attack("Peanut Butter");
	sandwich.takeDamage(8);
	sandwich.beRepaired(5);
	sandwich.attack("Peanut Butter");
	sandwich.attack("Peanut Butter");
	sandwich.attack("Peanut Butter");
	sandwich.attack("Peanut Butter");
	sandwich.attack("Peanut Butter");
	sandwich.attack("Peanut Butter");
	sandwich.beRepaired(1);
	sandwich.beRepaired(1);

	ScavTrap gateKeeper("Triton");

	gateKeeper._printer.roundTitlePrinter("ROUND 03");
	gateKeeper.attack("Peanut Butter");
	gateKeeper.takeDamage(2);
	gateKeeper.beRepaired(1);
	gateKeeper.guardGate();
	
	FragTrap subRoutine("Fragmented");
	
	subRoutine._printer.roundTitlePrinter("ROUND 04");
	subRoutine.attack("Peanut Butter");
	subRoutine.takeDamage(2);
	subRoutine.beRepaired(1);
	subRoutine.highFivesGuys();
	subRoutine.takeDamage(105);

	return 0;
}

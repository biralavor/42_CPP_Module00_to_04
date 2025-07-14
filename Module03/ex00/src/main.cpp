/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:58 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 20:01:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap peanut("Peanut Butter");
	ClapTrap sandwich("Sandwich");

	peanut._printer.roundTitlePrinter("ROUND 01");
	peanut.attack("Sandwich");
	peanut.takeDamage(3);
	peanut.beRepaired(2);
	peanut.takeDamage(10);
	peanut.takeDamage(3);
	
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

	return 0;
}
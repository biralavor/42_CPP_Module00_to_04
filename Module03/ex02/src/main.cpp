/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:58 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 13:50:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap peanut("Peanut Butter");
	ClapTrap sandwich("Sandwich");

	ScavTrap scavTrap("Scavenger");

	std::cout << BLUE << std::string(30, ':')
	<< " ROUND 01 " << std::string(30, ':')
	<< RESET << std::endl;
	peanut.attack("Sandwich");
	peanut.takeDamage(3);
	peanut.beRepaired(3);

	std::cout << BLUE << std::string(30, ':')
	<< " ROUND 02 " << std::string(30, ':')
	<< RESET << std::endl;
	sandwich.attack("Peanut Butter");
	sandwich.takeDamage(8);
	sandwich.beRepaired(5);

	std::cout << BLUE << std::string(30, ':')
	<< " ROUND 03 " << std::string(30, ':')
	<< RESET << std::endl;
	scavTrap.attack("Peanut Butter");
	scavTrap.takeDamage(2);
	scavTrap.beRepaired(1);
	scavTrap.guardGate();


	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:12:58 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/13 18:05:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap peanut("Peanut Butter");
	ClapTrap sandwich("Sandwich");
	
	peanut.attack("Sandwich");
	peanut.takeDamage(3);
	peanut.beRepaired(3);

	sandwich.attack("Peanut Butter");
	sandwich.takeDamage(8);
	sandwich.beRepaired(5);

	return 0;
}
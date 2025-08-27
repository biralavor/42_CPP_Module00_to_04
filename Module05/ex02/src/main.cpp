/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:43:08 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/27 12:25:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "#1 ----- TESTING BUREAUCRATS -----" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cerr << "\e[31m" << err.what() << "\e[0m" << std::endl;
	}

	std::cout << "\n#2 ----- TESTING INVALID GRADES for FORMS -----" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		// ShrubberyCreationForm shrub("FlowersInMyGarden-ShrubberyForm");
		// RobotomyRequestForm robot("iRobot-RobotomyForm");
		PresidentialPardonForm president("Macron-PresidentialPardonForm");

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		
		// std::cout << shrub << std::endl;
		// std::cout << robot << std::endl;
		std::cout << president << std::endl;

		// intern.signForm(shrub);
		// intern.executeForm(shrub);

		// boss.signForm(shrub);
		// boss.executeForm(shrub);

		// intern.signForm(robot);
		// intern.executeForm(robot);

		// boss.signForm(robot);
		// boss.executeForm(robot);

		intern.signForm(president);
		intern.executeForm(president);

		boss.signForm(president);
		boss.executeForm(president);

		// std::cout << shrub << std::endl;
		// std::cout << robot << std::endl;
		std::cout << president << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cerr << "\e[31m" << err.what() << "\e[0m" << std::endl;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:43:08 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/27 12:13:10 by umeneses         ###   ########.fr       */
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

	
	return 0;
}

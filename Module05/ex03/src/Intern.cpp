/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:14:59 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/28 16:00:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	this->_formTypes[0] = "Shrubbery Creation";
	this->_formTypes[1] = "Robotomy Request";
	this->_formTypes[2] = "Presidential Pardon";

	std::cout
	<< "\e[35m" << "Intern Class created with the following forms:"
	<< "\e[0m" << std::endl;
	for (int idx = 0; idx < POSSIBLE_FORMS; idx++)
		std::cout << "\e[36m" << "- " << this->_formTypes[idx] << "\e[0m" << std::endl;
	std::cout << std::endl;
}

Intern::~Intern(void)
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &rightSide)
{
	if (this != &rightSide)
		*this = rightSide;
	return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Error >> Intern didn't find this Form.";
}

int Intern::getActualFormIndex(const std::string formName) const
{
	for (int idx = 0; idx < POSSIBLE_FORMS; idx++)
	{
		if (formName == this->_formTypes[idx])
			return idx;
	}
	throw Intern::FormNotFoundException();
}

AForm *Intern::createShrubberyForm(const std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target) const
{
	int formIdx = this->getActualFormIndex(formName);
	AForm *createForm = NULL;
	switch (formIdx)
	{
		case 0:
			createForm = this->createShrubberyForm(target);
			break;
		case 1:
			createForm = this->createRobotomyForm(target);
			break;
		case 2:
			createForm = this->createPresidentialForm(target);
			break;
		default:
			break;
	}
	std::cout
	<< "\e[35m" << "Intern creates a \e[36m" << formName << "\e[0m"
	<< std::endl;
	return createForm;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:12:37 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/31 16:03:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Default Presidential Pardon",
		_minGradeToSign,
		_minGradeToExecute,
		"Default Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form",
		_minGradeToSign,
		_minGradeToExecute,
		target)
{	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: AForm(src)
{	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rightSide)
{
	if (this != &rightSide)
		AForm::operator=(rightSide);
	return *this;
}

void PresidentialPardonForm::announcement(void) const
{
	std::cout
	<< this->getTarget()
	<< " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
}

void PresidentialPardonForm::action(Bureaucrat const &executor) const
{
	this->announcement();
	std::cout
	<< "\e[34m" << executor.getName()
	<< "\e[32m just successfully run the form \e[34m"
	<< this->getType() << "\e[0m" <<std::endl;
}

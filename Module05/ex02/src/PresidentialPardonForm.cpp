/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:12:37 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/27 11:25:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Default Presidential Pardon", _minGradeToSign, _minGradeToExecute)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target, _minGradeToSign, _minGradeToExecute)
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
	requirementsController(executor);
	announcement();
}

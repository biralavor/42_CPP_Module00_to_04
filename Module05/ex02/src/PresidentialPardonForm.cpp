/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:12:37 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/25 15:26:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target, 25, 5)
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
		*this = rightSide;
	return *this;
}

void PresidentialPardonForm::action(void) const
{
	std::cout
	<< this->getTarget()
	<< " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
}
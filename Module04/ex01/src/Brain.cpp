/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:05:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 16:23:33 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	_printer.constructorTitlePrinter("Default Brain", "");
}

// Brain::Brain(std::string idea)
// {

// }

Brain::~Brain(void)
{
	_printer.destructorTitlePrinter("Default Brain", "");
}

Brain::Brain(Brain const &src)
{
	for (int idx = 0; idx < MAX_IDEAS; idx++)
		_ideas[idx] = src._ideas[idx];
}

Brain &Brain::operator=(const Brain &rightSide)
{
	if (this != &rightSide)
	{
		for (int idx = 0; idx < MAX_IDEAS; idx++)
			_ideas[idx] = rightSide._ideas[idx];
	}
	return *this;
}
	
std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= MAX_IDEAS)
		return NULL;
	return _ideas[idx];
}

void Brain::setIdea(int idx, std::string newIdea)
{
	if (idx < 0 || idx > MAX_IDEAS)
		return ;
	_ideas[idx] = newIdea;
}

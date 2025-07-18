/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:58:14 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 16:25:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Utils.hpp"

const int MAX_IDEAS = 100;

class Brain
{
	Utils _printer;

protected:
	std::string _ideas[MAX_IDEAS];

public:
	Brain(void);
	virtual ~Brain(void);
	Brain(Brain const &src);
	Brain &operator=(const Brain &rightSide);
	
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string newIdea);
};

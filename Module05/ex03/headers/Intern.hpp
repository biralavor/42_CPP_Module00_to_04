/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:07:25 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/27 15:08:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern : public AForm
{

public:
	Intern(void);
	~Intern(void);
	Intern(Intern const &src);
	Intern &operator=(Intern const &rightSide);
	
	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	AForm *makeForm(const std::string formName, const std::string target) const;
};

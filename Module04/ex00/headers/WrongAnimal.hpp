/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:07:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:36:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Utils.hpp"

class WrongAnimal
{
	std::string _className;
protected:
	std::string _type;
public:
	Utils		_printer;

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	virtual ~WrongAnimal(void);
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator=(const WrongAnimal &rightSide);
	void setType(const std::string newType);
	std::string getType(void) const;
	void makeSound(void) const;
};

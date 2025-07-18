/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:42 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 12:23:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Utils.hpp"

class AAnimal
{
	std::string _className;
protected:
	std::string _type;

public:
	Utils _printer;

public:
	AAnimal(void);
	AAnimal(std::string type);
	virtual ~AAnimal(void);
	AAnimal(AAnimal const &src);
	AAnimal &operator=(const AAnimal &rightSide);
	void setType(const std::string newType);
	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};

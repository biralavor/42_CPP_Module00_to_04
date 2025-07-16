/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:42 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 19:18:07 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(Animal const &src);
	Animal &operator=(Animal const &rightSide);
	void setType(const std::string newType);
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

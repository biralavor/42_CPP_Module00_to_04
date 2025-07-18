/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:59:33 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 14:40:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	std::string _className;
public:
	Dog(void);
	Dog(std::string type);
	virtual ~Dog(void);
	Dog(Dog const &src);
	Dog &operator=(Dog const &rightSide);
	
	void makeSound(void) const;
};

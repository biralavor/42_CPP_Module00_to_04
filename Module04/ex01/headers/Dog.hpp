/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:59:33 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 19:48:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	std::string _className;
	Brain		*_myBrain;

public:
	Dog(void);
	Dog(std::string type);
	virtual ~Dog(void);
	Dog(Dog const &src);
	Dog &operator=(Dog const &rightSide);
	
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

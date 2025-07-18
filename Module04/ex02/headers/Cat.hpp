/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:47:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/18 12:25:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	std::string _className;
	Brain		*_myBrain;

public:
	Cat(void);
	Cat(std::string type);
	virtual ~Cat(void);
	Cat(Cat const &src);
	Cat &operator=(Cat const &rightSide);

	void makeSound(void) const;
	Brain *getBrain(void) const;
};

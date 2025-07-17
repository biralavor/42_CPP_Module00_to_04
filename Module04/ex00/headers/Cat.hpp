/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:47:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 14:40:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	std::string _className;
public:
	Cat(void);
	Cat(std::string type);
	virtual ~Cat(void);
	Cat(Cat const &src);
	Cat &operator=(Cat const &rightSide);

	void makeSound(void) const;
};

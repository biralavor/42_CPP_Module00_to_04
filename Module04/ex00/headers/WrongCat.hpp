/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:10:30 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/17 17:38:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	std::string _className;
public:
				WrongCat(void);
				WrongCat(std::string type);
	virtual 	~WrongCat(void);
				WrongCat(WrongCat const &src);
	WrongCat 	&operator=(const WrongCat &rightSide);

	void 		makeSound(void) const;
};

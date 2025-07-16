/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:49:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/16 14:27:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	std::string _classType;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		virtual ~FragTrap(void);
		FragTrap(FragTrap const &src);
		FragTrap &operator=(FragTrap const &rightSide);

		void highFivesGuys(void);
};

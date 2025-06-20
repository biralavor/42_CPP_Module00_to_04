/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:31:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/06/20 19:41:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Megaphone.hpp"

int megaphone(int argc, char **argv)
{
	std::string str;
	if (argc == 1)
	{
		std::cout
		<< ">>> SHOUTING IS BAD <<<" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			str += argv[i];
			if (i < argc - 1)
				str += " ";
		}
		std::cout
		<< str << std::endl;
	}
	return 0;
}

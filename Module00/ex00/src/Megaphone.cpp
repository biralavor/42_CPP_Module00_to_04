/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:31:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 09:28:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Megaphone.hpp"

std::string megaphone(int argc, char **argv)
{
	std::string result;
	int			i;
	int			j;

	result = "";
	i = 0;
	if (argc == 1)
	{
		return ">>> SHOUTING IS BAD <<<";
	}
	else
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				result += std::toupper(argv[i][j]);
			if (i < argc - 1)
				result += ' ';
		}
		return result;
	}
}

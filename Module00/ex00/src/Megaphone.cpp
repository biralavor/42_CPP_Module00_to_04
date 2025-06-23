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
	std::string result;
	int			i;
	int			j;

	result = "";
	i = 0;
	if (argc == 1)
	{
		std::cout <<
		">>> SHOUTING IS BAD <<<" <<
		std::endl;
	}
	else
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				result += toupper(argv[i][j]);
			result += ' ';
		}
		std::cout
		<< result << std::endl;
	}
	return 0;
}

int main(int argc, char** argv)
{
	std::cout << 
	megaphone(argc, argv) << 
	std::endl;
	return EXIT_SUCCESS;
}

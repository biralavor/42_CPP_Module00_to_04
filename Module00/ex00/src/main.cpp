/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:30:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/06/24 15:01:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Megaphone.hpp"

int main(int argc, char** argv)
{
	std::string	result;

	result = megaphone(argc, argv);
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:25:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/14 17:44:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void Utils::roundTitlePrinter(std::string title)
{
    int width = 30;
    char paddingChar = ':';
    int paddingSize = (width - title.length()) + 2;

    std::cout << BLUE << std::string(width * 2, paddingChar) << std::endl;
    std::cout << " " << std::string(paddingSize, paddingChar)
	<< " " + title + " " << std::string(paddingSize, paddingChar) << std::endl;
    std::cout << std::string(width * 2, paddingChar)
	<< RESET << std::endl;
}

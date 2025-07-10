/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:19:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 12:58:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl        harlMachine;
    std::string level;

    while (true)
    {
        std::cout << "Enter a complaint level (DEBUG, INFO, WARNING, ERROR): ";
        if (!(std::getline(std::cin, level)))
        {
            if (std::cin.eof())
                level = "EOF";
        }
        if (level == "EXIT" || level == "EOF")
        {
            std::cout << "\nExiting the program." << std::endl;
            break;
        }
        harlMachine.complain(level);
    }
    return 0;
}

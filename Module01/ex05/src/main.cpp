/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:19:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:43 by umeneses         ###   ########.fr       */
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
        std::getline(std::cin, level);
        if (level == "EXIT")
            break;
        harlMachine.complain(level);
    }
    return 0;
}

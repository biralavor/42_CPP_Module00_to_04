/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:59:42 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/08 17:45:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    complainAction[DEBUG] = &Harl::debug;
    complainAction[INFO] = &Harl::info;
    complainAction[WARNING] = &Harl::warning;
    complainAction[ERROR] = &Harl::error;
}

Harl::~Harl()
{
    // Destructor
}


void Harl::error(void)
{
    std::cout
    << "[ ERROR ]\n"
    << "[ unrecoverable error has occurred, almost a BSOD... ops ]\n"
    << "[ SORRY! I CAN'T HELP YOU! ] \n"
    << std::endl;
}

void Harl::warning(void)
{
    std::cout
    << "[ WARNING ]\n"
    << "[ something went wrong, but I still can help you. ]\n"
    << "[ be patient and try again later... in a few hours ] \n"
    << std::endl;
}

void Harl::info(void)
{
    std::cout
    << "[ INFO ]\n"
    << "[ i'm tracking all data to generate reports. ]\n"
    << "[ please, let me know what you need. ] \n"
    << std::endl;
}

void Harl::debug(void)
{
    std::cout
    << "[ DEBUG ]\n"
    <<  "[ i'm here to help you with your code. ]\n"
    << std::endl;
}

void Harl::complain(std::string level)
{
    std::string actualLevel[MAX_ACTIONS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t idxChar = 0; idxChar < level.length(); idxChar++)
        level[idxChar] = toupper(level[idxChar]);
    for (int idx = 0; idx < MAX_ACTIONS; idx++)
    {
        if (level == actualLevel[idx])
        {
            (this->*complainAction[idx])();
            return;
        }
    }
}
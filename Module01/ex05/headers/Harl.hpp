/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:40:30 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/08 17:47:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

const int MAX_ACTIONS = 4;

class Harl
{
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    enum ComplainLevels
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };
    typedef void (Harl::*PointerToMemberAction)(void);
    PointerToMemberAction complainAction[MAX_ACTIONS];
public:
    void complain(std::string level);
    Harl();
    ~Harl();
};

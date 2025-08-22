/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:50:06 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/22 15:48:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

const std::string RESET = "\e[0m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";
const std::string YELLOW = "\e[33m";
const std::string BLUE = "\e[34m";

class Utils
{

public:
    void constructorTitlePrinter(std::string type, std::string objectName) const;
    void destructorTitlePrinter(std::string type, std::string objectName) const;
    void statusConstructorPrinter(std::string type, int value) const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:59 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/20 17:32:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Utils.hpp"

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat(void);
    Bureaucrat(Bureaucrat const &src);
    
    std::string getName(void) const;
    int getGrade(void) const;
    void setGrade(int grade);
    void incrementGrade(void);
    void decrementGrade(void);

public:
    Utils _printer;
};

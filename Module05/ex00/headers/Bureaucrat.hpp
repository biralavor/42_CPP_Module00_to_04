/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:59 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/21 15:22:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Utils.hpp"
#include <exception>

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;

public:
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat(void);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &rightSide);
    std::exception GradeTooHighException(void) const;
    std::exception GradeTooLowException(void) const;
    std::string getName(void) const;
    int getGrade(void) const;
    void setGrade(int grade);
    void incrementGrade(void);
    void decrementGrade(void);

public:
    Utils _printer;
};

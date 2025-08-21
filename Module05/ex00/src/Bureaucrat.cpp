/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:59:45 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/21 15:34:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
    : _name("Default"), _grade(42)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    std::cout << "Parameterized constructor called" << std::endl;
    setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    std::cout
    << "Copy constructor called for: "
    << YELLOW << _name << RESET
    << std::endl;
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rightSide)
{
    std::cout
    << "Assignment operator called for: "
    << YELLOW << rightSide.getName() << RESET
    << std::endl;
    if (this != &rightSide)
    {
        // this->_name = rightSide.getName();
        this->_grade = rightSide.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
    this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
    this->_grade++;
}

std::exception Bureaucrat::GradeTooHighException(void) const
{
    return std::exception();
}

std::exception Bureaucrat::GradeTooLowException(void) const
{
    return std::exception();
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

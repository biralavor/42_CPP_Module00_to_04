/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:59:45 by umeneses          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/08/20 18:00:23 by umeneses         ###   ########.fr       */
=======
/*   Updated: 2025/08/22 12:39:07 by umeneses         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
<<<<<<< Updated upstream
    : _name("Default"), _grade(150)
=======
    : _name("Default"), _grade(LOWEST_GRADE)
>>>>>>> Stashed changes
{
    std::cout << "Default constructor called" << std::endl;
}

<<<<<<< Updated upstream
Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade)
{
    std::cout << "Parameterized constructor called" << std::endl;
=======
Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade)
{
    std::cout << "Parameterized constructor called" << std::endl;
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
>>>>>>> Stashed changes
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name)
{
    std::cout << "Copy constructor called for: " << _name << std::endl;
    *this = src;
}

<<<<<<< Updated upstream
=======
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rightSide)
{
    std::cout << "Assignment operator called for: " << rightSide.getName() << std::endl;
    if (this != &rightSide)
    {
        // _name is const, so it cannot be changed after construction.
        // Only non-const members can be assigned.
        this->_grade = rightSide.getGrade();
    }
    return *this;
}

>>>>>>> Stashed changes
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
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

<<<<<<< Updated upstream
void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
=======
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
>>>>>>> Stashed changes
}

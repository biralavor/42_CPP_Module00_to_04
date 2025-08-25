/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:18:16 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/23 22:23:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::MAX_GRADE;
const int Form::MIN_GRADE;

Form::Form(void)
    : _name("Default"), _isSigned(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw GradeTooHighException();
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw GradeTooLowException();
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &src)
    : _name(src.getName()),
    _isSigned(src.getSignature()),
    _gradeToSign(src.getGradeToSign()),
    _gradeToExecute(src.getGradeToExecute())
{
    std::cout << "Form copy constructor called for: " << _name << std::endl;
}

Form &Form::operator=(Form const &rightSide)
{
    std::cout << "Form assignment operator called for: "
    << rightSide.getName() << std::endl;
    if (this != &rightSide)
    {
        this->_isSigned = rightSide.getSignature();
    }
    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getSignature(void) const
{
    return this->_isSigned;
}

int Form::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

bool Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
    return true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form '" << form.getName()
        << "', status: " << (form.getSignature() ? "signed" : "not signed")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:18:16 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/26 12:46:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
    : _name("Default Abstract Form"),
    _isSigned(false),
    _gradeToSign(MIN_GRADE),
    _gradeToExecute(MIN_GRADE)
{
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw GradeTooHighException();
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
}

AForm::AForm(AForm const &src)
    : _name(src.getName()),
    _isSigned(src.getSignature()),
    _gradeToSign(src.getGradeToSign()),
    _gradeToExecute(src.getGradeToExecute())
{
}

AForm &AForm::operator=(AForm const &rightSide)
{
    if (this != &rightSide)
    {
        this->_isSigned = rightSide.getSignature();
    }
    return *this;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getSignature(void) const
{
    return this->_isSigned;
}

int AForm::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
    return "Form is already signed";
}

void AForm::setSignature(bool status)
{
    this->_isSigned = status;
}

bool AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    this->setSignature(true);
    return true;
}

const std::string &AForm::getTarget(void) const
{
    return this->_target;
}

void AForm::execute(const Bureaucrat &bureaucrat)
{
    if (!this->getSignature())
        throw AForm::GradeTooLowException();
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    this->action();
}

std::ostream &operator<<(std::ostream &out, const AForm &abstractForm)
{
    out
    << "AForm '" << abstractForm.getName()
    << "', status: " << (abstractForm.getSignature() ? "signed" : "not signed")
    << ", grade to sign: " << abstractForm.getGradeToSign()
    << ", grade to execute: " << abstractForm.getGradeToExecute();
    return out;
}

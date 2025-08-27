/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:20:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/27 10:32:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    const std::string   _name;
    const std::string   _target;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    static const int    MAX_GRADE = 1;
    static const int    MIN_GRADE = 150;

public:
    AForm(void);
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    virtual ~AForm(void);
    AForm(AForm const &src);
    AForm &operator=(AForm const &rightSide);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class FormAlreadySignedException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    std::string getName(void) const;
    bool getSignature(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool beSigned(Bureaucrat &bureaucrat);
    void setSignature(bool status);

    const std::string &getTarget(void) const;
    void requirementsController(const Bureaucrat &executor);
    virtual void action(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &absForm);

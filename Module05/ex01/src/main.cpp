/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:57:24 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/23 22:13:12 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\e[0m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";
const std::string YELLOW = "\e[33m";
const std::string BLUE = "\e[34m";

int main(void)
{
    std::cout << YELLOW << "#1 Bureaucrat and Form VALID tests"
    << RESET << std::endl;
    
    try
    {
        Bureaucrat bureaucrat("John", 42);
        Form form("Form A", 50, 100);
        bureaucrat.signForm(form);
    }
    catch (const std::exception &e) {
        std::cerr
        << RED << e.what() << '\n' << RESET;
    }

    std::cout << YELLOW << "\n#2 GradeTooLow for Signing Forms tests"
    << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat("John", 42);
        Form form("Form B", 30, 60);
        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr
        << RED << e.what() << '\n' << RESET;
    }
    
    std::cout << YELLOW << "\n#3 GradeTooHigh for Signing Forms tests"
    << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat("John", 0);
        Form form("Form C", 30, 60);
        bureaucrat.signForm(form);
    }
    catch(const std::exception &e)
    {
        std::cerr
        << RED << e.what() << '\n' << RESET;
    }
    return 0;

}
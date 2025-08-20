/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:13 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/20 16:52:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat b1;
    Bureaucrat b2("John", 42);
    b1._printer.constructorTitlePrinter("Bureaucrat", b1.getName());
    b2._printer.constructorTitlePrinter("Bureaucrat", b2.getName());
    return 0;
}

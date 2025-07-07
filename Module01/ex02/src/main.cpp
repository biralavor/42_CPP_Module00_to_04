/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:23:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/07 12:30:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string chef = "HI THIS IS BRAIN";
    std::string *stringPTR = &chef;
    std::string &stringREF = chef;

    std::cout
    << "\n  String variable address: " << &chef << "\n"
    << "Address held by stringPTR: " << stringPTR << "\n"
    << "Address held by stringREF: " << &stringREF << "\n"
    << std::endl;

    std::cout
    << "        String variable value: " << chef << "\n"
    << "Value pointed to by stringPTR: " << *stringPTR << "\n"
    << "Value pointed to by stringREF: " << stringREF << "\n"
    << std::endl;

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:13 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/21 17:18:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
    try {
        std::cout << "--- Testing Valid Bureaucrat ---" << std::endl;
        Bureaucrat b1("Zaphod", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.incrementGrade(); // This will throw
        std::cout << "This should not be printed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Grade Too Low ---" << std::endl;
    try {
        Bureaucrat b2("Arthur", 151);
        std::cout << b2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Grade Too High ---" << std::endl;
    try {
        Bureaucrat b3("Ford", 0);
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:50:52 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/05 18:50:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;

    phonebook.addContact("1John", "Doe", "JoD", "123-456-7890", "Loves pizza");
    phonebook.addContact("2Jane", "Smith", "JayS", "987-654-3210", "Hates spiders");
    phonebook.addContact("3Bob", "Johnson", "BobJ", "555-555-5555", "Afraid of heights");
    phonebook.phoneBookManager();

    return 0;
}

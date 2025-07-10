/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:51:26 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 09:47:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook
{
    int     contactCounter;
    int     nextSlotIdx;
    Contact *allContacts[MAX_CONTACTS];

private:
    std::string getUserInput();
    std::string getInputToFillContact(const std::string &inputType);
    int userInputAsNumber(std::string &userInput, int &appState);
    int userInputAsWord(std::string &userInput, int &appState);
    void searchContactManager(void);
    void addContactManager(void);
    bool isActionStillOn(bool &isActionOn, const std::string &action);

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const std::string &firstName,
        const std::string &lastName, const std::string &nickName,
        const std::string &phoneNumber, const std::string &darkestSecret);
    const Contact *getContact(int idx) const;
    void phoneBookManager(void);
};

#pragma once
#include <iostream>
#include <string>
#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook
{
    int contactCounter;
    int nextSlotIdx;
    Contact *allContacts[MAX_CONTACTS];

private:
    int userInputAsANumber(std::string &userInput, int &appState);
    int userInputAsAWord(std::string &userInput, int &appState);
    std::string getUserInput();
    void searchContactManager() const;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const std::string &firstName,
        const std::string &lastName, const std::string &nickName,
        const std::string &phoneNumber, const std::string &darkestSecret);
    const Contact *getContact(int idx) const;
    void phoneBookManager(void);
};

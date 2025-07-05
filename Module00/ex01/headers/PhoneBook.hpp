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
    bool userInputAsANumber(std::string &userInput);
    bool userInputAsAWord(std::string &userInput);

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const std::string &firstName,
        const std::string &lastName, const std::string &nickName,
        const std::string &phoneNumber, const std::string &darkestSecret);
    const Contact *getContact(int idx) const;
    void searchContact(int idx) const;
    void phoneBookManager(void);
};

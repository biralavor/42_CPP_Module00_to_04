/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:51:11 by umeneses          #+#    #+#             */
/*   Updated: 2025/07/10 16:22:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Printers.hpp"

PhoneBook::PhoneBook()
{
    this->contactCounter = 0;
    this->nextSlotIdx = 0;

    std::cout << "Phonebook Constructor was activated." << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
        this->allContacts[i] = NULL;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Phonebook Destructor was activated." << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        if (this->allContacts[i] != NULL)
            delete this->allContacts[i];
    }
}

void PhoneBook::addContact(const std::string &firstName,
    const std::string &lastName, const std::string &nickName,
    const std::string &phoneNumber, const std::string &darkestSecret)
{
    if (this->allContacts[this->nextSlotIdx] != NULL)
        delete this->allContacts[this->nextSlotIdx];
    this->allContacts[this->nextSlotIdx] = new Contact(firstName, lastName,
        nickName, phoneNumber, darkestSecret);
    this->nextSlotIdx = (this->nextSlotIdx + 1) % MAX_CONTACTS;
    if (this->contactCounter < MAX_CONTACTS)
        this->contactCounter++;
}

std::string PhoneBook::getUserInput()
{
    std::string userInput;

    std::cout << "Please, choose an option: ";
    if (!(std::cin >> userInput))
    {
        if (std::cin.eof())
            return "EOF";
    }
    for (unsigned int idx = 0; idx < userInput.size(); idx++)
        userInput[idx] = std::toupper(userInput[idx]);
    return userInput;
}

std::string PhoneBook::getInputToFillContact(const std::string &inputType)
{
    std::string input;

    std::cout << "Enter " << inputType << ": ";
    if (!(std::cin >> input))
    {
        if (std::cin.eof())
            return "EOF";
    }
    if (input.empty())
    {
        std::cerr << "Input cannot be empty. Please try again." << std::endl;
        return getInputToFillContact(inputType);
    }
    if (input.size() < 3)
    {
        std::cerr << "[" << inputType << "] is too short. "
        << "It has to be at least 3 characters." << std::endl;
        return getInputToFillContact(inputType);
    }
    return input;
}

const Contact *PhoneBook::getContact(int idx) const
{
    if (idx < 0 || idx >= this->contactCounter)
        return NULL;
    return this->allContacts[idx];
}

bool PhoneBook::isActionStillOn(bool &isActionOn, const std::string &action)
{
    std::string userInput;

    while (isActionOn)
    {
        std::cout << "Do you want to " << action << " another contact? (Y/N): ";
        if (!(std::cin >> userInput))
        {
            if (std::cin.eof() || userInput == "N" || userInput == "n")
                isActionOn = false;
        }
        else if (userInput == "Y" || userInput == "y")
        {
            isActionOn = true;
            break;
        }
        else
        {
            std::cerr << "Invalid input [" << userInput << "]. "
            << "Please enter 'Y' or 'N'." << std::endl;
        }
    }
    return isActionOn;
}

void PhoneBook::addContactManager(void)
{
    bool        isActionOn = true;
    std::string userInput;
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    while (isActionOn)
    {
        firstName = getInputToFillContact("First Name");
        lastName = getInputToFillContact("Last Name");
        nickName = getInputToFillContact("Nickname");
        phoneNumber = getInputToFillContact("Phone Number");
        darkestSecret = getInputToFillContact("Darkest Secret");
        if (firstName == "EOF" || lastName == "EOF" ||
            nickName == "EOF" || phoneNumber == "EOF" ||
            darkestSecret == "EOF")
        {
            std::cout << "\nEnd of input detected. Exiting." << std::endl;
            isActionOn = false;
            break ;
        }
        this->addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
        std::cout << "Contact added successfully!" << std::endl;
        isActionOn = isActionStillOn(isActionOn, "add");
    }
}

void PhoneBook::searchContactManager(void)
{
    int         inputAsInt;
    bool        isActionOn = true;
    std::string userInput;
    Printers    printer;

    if (this->contactCounter == 0)
    {
        std::cerr << "No contacts available. Please add a contact first."
        << std::endl;
        return;
    }
    while (isActionOn)
    {
        std::cout << "Enter the index of the contact you want to search [1: "
        << this->contactCounter << "] (or type '!' to exit): ";
        if (!(std::cin >> userInput))
        {
            if (std::cin.eof())
                break ;
        }
        if (userInput == "!")
        {
            std::cout << "Exiting search." << std::endl;
            isActionOn = false;
            break;
        }
        if (userInput[0] <= '0' || userInput[0] > '0' + this->contactCounter)
        {
            std::cerr << "Invalid Contact index[" << userInput << "]. "
            << "Please enter a valid Contact position." << std::endl;
        }
        else
        {
            inputAsInt = userInput[0] - '0' - 1;
            const Contact contact = *this->getContact(inputAsInt);
            printer.searchContactHeaderPrinter();
            printer.searchContactDetailsPrinter(inputAsInt, contact);
            isActionOn = isActionStillOn(isActionOn, "search for");
        }
    }
}

int PhoneBook::userInputAsNumber(std::string &userInput, int &appState)
{
    switch (userInput[0])
    {
        case '1':
            addContactManager();
            break;
        case '2':
            searchContactManager();
            break;
        case '3':
            std::cout << "Exiting PhoneBook Application.\n" << std::endl;
            appState = 0;
            break;
        default:
            appState =  2;
            break;
    }
    return appState;
}

int PhoneBook::userInputAsWord(std::string &userInput, int &appState)
{
    if (userInput == "ADD")
        addContactManager();
    else if (userInput == "SEARCH")
        searchContactManager();
    else if (userInput == "EXIT")
    {
        std::cout << "Exiting PhoneBook Application.\n" << std::endl;
        appState = 0;
    }
    else
        appState = 2;
    return appState;
}

void PhoneBook::phoneBookManager(void)
{
    int         appState = 1;
    Printers    printer;
    std::string userInput;

    while (appState != 0)
    {
        printer.phoneBookPrinter(*this);
        printer.phoneBookMainMenuPrinter();
        userInput = getUserInput();
        if (userInput == "EOF")
        {
            std::cout << "\nEnd of input detected. Exiting." << std::endl;
            appState = 0;
            break;
        }
        if (userInput.size() == 1)
            appState = userInputAsNumber(userInput, appState);
        else if (userInput.size() > 1)
            appState = userInputAsWord(userInput, appState);
        if (appState == 2)
            std::cerr << "Invalid option [" << userInput << "]. "
            << "Try again." << std::endl;
    }
}

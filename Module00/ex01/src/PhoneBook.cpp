#include "PhoneBook.hpp"
#include "Printers.hpp"

PhoneBook::PhoneBook()
{
    this->contactCounter = 0;
    this->nextSlotIdx = 0;

    std::cout << "Phonebook Constructor were activated." << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
        this->allContacts[i] = NULL;
    phoneBookManager();
}

PhoneBook::~PhoneBook()
{
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        if (this->allContacts[i] != NULL)
            delete this->allContacts[i];
    }
    std::cout << "Phonebook Destructor were activated." << std::endl;
}

void PhoneBook::addContact(const std::string &firstName,
    const std::string &lastName, const std::string &nickName,
    const std::string &phoneNumber, const std::string &darkestSecret)
{
    if (this->allContacts[this->nextSlotIdx] != NULL)
        delete this->allContacts[this->nextSlotIdx];
    this->allContacts[this->nextSlotIdx] = new Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    this->nextSlotIdx = (this->nextSlotIdx + 1) % MAX_CONTACTS;
    if (this->contactCounter < MAX_CONTACTS)
        this->contactCounter++;
}

const Contact *PhoneBook::getContact(int idx) const
{
    if (idx < 0 || idx >= this->contactCounter)
    {
        return NULL;
    }
    return this->allContacts[idx];
}

void PhoneBook::searchContact(int idx) const
{
    Printers printer;

    idx--;
    if (idx < 0 || idx >= this->contactCounter)
    {
        std::cerr << "Invalid Contact index[" << idx + 1 << "]. "
        << "Please enter a valid Contact position." << std::endl;
        return;
    }
    const Contact contact = *this->getContact(idx);
    printer.searchContactHeaderPrinter();
    printer.searchContactDetailsPrinter(idx, contact);
}

std::string PhoneBook::getUserInput()
{
    std::string userInput;

    std::cout << "Please, choose an option: ";
    std::cin >> userInput;
    for (unsigned int idx = 0; idx < userInput.size(); idx++)
        userInput[idx] = toupper(userInput[idx]);
    return userInput;
}

int PhoneBook::userInputAsANumber(std::string &userInput, bool &isAppRunning)
{
    while (isAppRunning)
    {
        switch (userInput[0])
        {
            case '1':
                // Add Contact
                break;
            case '2':
                // Search Contact
                break;
            case '3':
                std::cout << "Exiting PhoneBook Application." << std::endl;
                isAppRunning = false;
                break;
            default:
                return 2;
        }
    }
    return isAppRunning;
}

int PhoneBook::userInputAsAWord(std::string &userInput, bool &isAppRunning)
{
    while (isAppRunning)
    {
        if (userInput == "ADD")
        {
            // Add Contact
        }
        else if (userInput == "SEARCH")
        {
            // Search Contact
        }
        else if (userInput == "EXIT")
        {
            std::cout << "Exiting PhoneBook Application." << std::endl;
            isAppRunning = false;
        }
        else
            return 2;
    }
    return isAppRunning;
}

void PhoneBook::phoneBookManager(void)
{
    Printers    printer;
    std::string userInput;
    bool        isAppRunning = true;
    int         appState = 0;

    printer.phoneBookPrinter(*this);
    printer.phoneBookMainMenuPrinter();
    while (isAppRunning)
    {
        userInput = getUserInput();
        if (userInput.size() == 1 && isdigit(userInput[0]))
            appState = userInputAsANumber(userInput, isAppRunning);
        else if (userInput.size() > 1)
            appState = userInputAsAWord(userInput, isAppRunning);
        if (appState == 2)
            std::cerr << "Invalid option [" << userInput << "]. Try again." << std::endl;
    }
}

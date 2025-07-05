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

void PhoneBook::phoneBookManager(void)
{
    Printers    printer;
    std::string userInput;
    bool isAppRunning = true;

    printer.phoneBookPrinter(*this);
    printer.phoneBookMainMenuPrinter();
    std::cin >> userInput;
    for (unsigned int idx = 0; idx < userInput.size(); idx++)
        userInput[idx] = toupper(userInput[idx]);
    while (isAppRunning)
    {
        if (userInput.size() == 1 && isdigit(userInput[0]))
            isAppRunning = userInputAsANumber(userInput);
        else
            isAppRunning = userInputAsAWord(userInput);
    }
}

bool PhoneBook::userInputAsANumber(std::string &userInput)
{
    bool isAppRunning = true;
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
                std::cerr << "Invalid option. Try again." << std::endl;
                std::cin >> userInput;
                userInput = toupper(userInput[0]);
                break;
        }
    }
    return isAppRunning;
}

bool PhoneBook::userInputAsAWord(std::string &userInput)
{
    bool isAppRunning = true;
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
        {
            std::cerr << "Invalid option. Try again." << std::endl;
            std::cin >> userInput;
            userInput = toupper(userInput[0]);
        }
    }
    return isAppRunning;
}
#include "PhoneBook.hpp"
#include "Printers.hpp"

PhoneBook::PhoneBook()
{
    this->contactCounter = 0;
    this->nextSlotIdx = 0;
    std::cout << "Phonebook Constructor were activated." << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
        this->allContacts[i] = NULL;
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

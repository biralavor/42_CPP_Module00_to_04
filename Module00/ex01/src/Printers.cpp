#include "Printers.hpp"
#include "PhoneBook.hpp"
#include <string.h>

const int COLUMN_WIDTH = 10;

void Printers::oneColumnPrinter(const std::string &str) const
{
    int size = str.size();
    int startPoint = COLUMN_WIDTH / 2;
    std::cout << "|";
    if (size > COLUMN_WIDTH)
        std::cout << str.substr(0, COLUMN_WIDTH - 1) + ".";
    else
    {
        if (size != 1 && startPoint >= size)
            startPoint = (COLUMN_WIDTH - size) / 2;
        else if (size != 1 && startPoint < size)
            startPoint -= size / 2;
        for (int i = 0; i < startPoint; i++)
            std::cout << " ";
        std::cout
        << std::setw(COLUMN_WIDTH - startPoint)
        << std::left << str;
    }
}

void Printers::contactDetailsAsARowPrinter(const Contact &contact) const
{
    oneColumnPrinter(contact.getName());
    oneColumnPrinter(contact.getNickName());
    oneColumnPrinter(contact.getPhoneNumber());
    // oneColumnPrinter(contact.getDarkestSecret());
}

void Printers::contactDetailsAsAColumnPrinter(int idx, const Contact &contact) const
{
    std::string idxStr;

    idxStr = idx + 48;
    oneColumnPrinter("Index");
    oneColumnPrinter(idxStr);
    std::cout << "\n";
    oneColumnPrinter("Name");
    oneColumnPrinter(contact.getName());
    std::cout << "\n";
    oneColumnPrinter("Nickname");
    oneColumnPrinter(contact.getNickName());
    std::cout << "\n";
    oneColumnPrinter("Phone Number");
    oneColumnPrinter(contact.getPhoneNumber());
    std::cout << "\n";
}

void Printers::phoneBookHeaderPrinter() const
{
    std::cout << "\n\t\tPhoneBook Contacts:" << std::endl;
    std::cout << " ___________________________________________" << std::endl;
    oneColumnPrinter("Index");
    oneColumnPrinter("Name");
    oneColumnPrinter("Nickname");
    oneColumnPrinter("Phone Number");
    std::cout << "|" << std::endl;
    std::cout << "|===========================================|" << std::endl;
}

void Printers::phoneBookPrinter(const PhoneBook &phoneBook) const
{
    std::string idxStr;

    phoneBookHeaderPrinter();
    for (int idx = 0; idx < MAX_CONTACTS; idx++)
    {
        idxStr = idx + 48 + 1;
        oneColumnPrinter(idxStr);
        const Contact *contact = phoneBook.getContact(idx);
        if (contact)
            contactDetailsAsARowPrinter(*contact);
        else
            std::cout << " ------------------------------ |";
        std::cout << "|" << std::endl;
    }
    std::cout << " ########################################### \n" << std::endl;
}

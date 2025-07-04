#include "Printers.hpp"
#include "PhoneBook.hpp"

const int COLUMN_WIDTH = 10;

void Printers::columnPrinter(const std::string &str) const
{
    int size = str.size();
    int startPoint = COLUMN_WIDTH / 2;
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
    std::cout << "|";
}

void Printers::contactDetailsPrinter(const Contact &contact) const
{
    columnPrinter(contact.getName());
    columnPrinter(contact.getNickName());
    columnPrinter(contact.getPhoneNumber());
    // columnPrinter(contact.getDarkestSecret());
}

void Printers::headerPrinter() const
{
    std::cout << "PhoneBook Contacts:" << std::endl;
    std::cout << "|";
    columnPrinter("Index");
    columnPrinter("Name");
    columnPrinter("Nickname");
    columnPrinter("Phone Number");
    std::cout << std::endl;
}

void Printers::phoneBookPrinter(const PhoneBook &phoneBook) const
{
    std::string idxStr;

    headerPrinter();
    for (int idx = 0; idx < MAX_CONTACTS; idx++)
    {
        std::cout << "|";
        idxStr = idx + 48 + 1;
        columnPrinter(idxStr);
        const Contact *contact = phoneBook.getContact(idx);
        if (contact)
            contactDetailsPrinter(*contact);
        else
            std::cout << " ------------------------------ |";
        std::cout << std::endl;
    }
}

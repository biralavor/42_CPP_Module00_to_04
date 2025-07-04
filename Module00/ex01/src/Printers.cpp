#include "Printers.hpp"
#include "PhoneBook.hpp"

const int COLUMN_WIDTH = 10;

void Printers::oneColumnPrinter(const std::string &str) const
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

void Printers::contactDetailsAsARowPrinter(const Contact &contact) const
{
    oneColumnPrinter(contact.getName());
    oneColumnPrinter(contact.getNickName());
    oneColumnPrinter(contact.getPhoneNumber());
    // oneColumnPrinter(contact.getDarkestSecret());
}

void Printers::headerPrinter() const
{
    std::cout << "\n\t\tPhoneBook Contacts:" << std::endl;
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|";
    oneColumnPrinter("Index");
    oneColumnPrinter("Name");
    oneColumnPrinter("Nickname");
    oneColumnPrinter("Phone Number");
    std::cout << "\n|===========================================|" << std::endl;
}

void Printers::phoneBookPrinter(const PhoneBook &phoneBook) const
{
    std::string idxStr;
    
    headerPrinter();
    for (int idx = 0; idx < MAX_CONTACTS; idx++)
    {
        std::cout << "|";
        idxStr = idx + 48 + 1;
        oneColumnPrinter(idxStr);
        const Contact *contact = phoneBook.getContact(idx);
        if (contact)
        contactDetailsAsARowPrinter(*contact);
        else
        std::cout << " ------------------------------ |";
        std::cout << std::endl;
    }
    std::cout << " ########################################### \n" << std::endl;
}

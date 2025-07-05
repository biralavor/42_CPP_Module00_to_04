#include "Printers.hpp"
#include "PhoneBook.hpp"

const int COLUMN_WIDTH = 10;
const int TOTAL_COLUMNS = 4;
const char headTitleLayout = '_';
const char tailTitleLayout = '`';
const char edgeLayout = '|';
const char tailLayout = '#';
const char emptySlot = '*';
const char lineDivision = '-';

void Printers::oneColumnPrinter(const std::string &str) const
{
    int size = str.size();
    int startPoint = COLUMN_WIDTH / 2;
    std::cout << edgeLayout;
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
    std::cout << edgeLayout << std::endl;
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision);
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision)
    << edgeLayout << std::endl;
    oneColumnPrinter("Name");
    oneColumnPrinter(contact.getName());
    std::cout << edgeLayout << std::endl;
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision);
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision)
    << edgeLayout << std::endl;
    oneColumnPrinter("Nickname");
    oneColumnPrinter(contact.getNickName());
    std::cout << edgeLayout << std::endl;
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision);
    std::cout << edgeLayout << std::string(COLUMN_WIDTH, lineDivision)
    << edgeLayout << std::endl;
    oneColumnPrinter("Phone Number");
    oneColumnPrinter(contact.getPhoneNumber());
    std::cout << edgeLayout << std::endl;
    std::cout << " " << std::string((COLUMN_WIDTH * 2) + 1, '#')
    << std::endl;
}

void Printers::phoneBookHeaderPrinter() const
{
    std::string title = "PhoneBook Contacts";
    int blankSpace = ((COLUMN_WIDTH * TOTAL_COLUMNS) - title.size() + 1) / 2;
    int nbrOfCopies = (COLUMN_WIDTH * TOTAL_COLUMNS) + TOTAL_COLUMNS - 1;
    std::cout << "\n"
    << edgeLayout << std::string(blankSpace + 1, headTitleLayout)
    << title << std::string(blankSpace + 1, headTitleLayout) << edgeLayout << "\n";
    oneColumnPrinter("Index");
    oneColumnPrinter("Name");
    oneColumnPrinter("Nickname");
    oneColumnPrinter("Phone Number");
    std::cout
    << edgeLayout << "\n"
    << edgeLayout << std::string(nbrOfCopies, tailTitleLayout)
    << edgeLayout << std::endl;
}

void Printers::searchContactHeaderPrinter() const
{
    std::string title = "Contact Details";
    int blankSpace = ((COLUMN_WIDTH * 2) - title.size() + 1) / 2;

    std::cout
    << " " 
    << std::string((COLUMN_WIDTH * 2) + 1, headTitleLayout) << " " << "\n";

    std::cout
    << edgeLayout << std::string(blankSpace, ' ')
    << title << std::string(blankSpace, ' ') << edgeLayout << "\n";

    std::cout
    << edgeLayout << std::string(COLUMN_WIDTH, tailTitleLayout)
    << edgeLayout << std::string(COLUMN_WIDTH, tailTitleLayout)
    << edgeLayout << std::endl;
}

void Printers::phoneBookPrinter(const PhoneBook &phoneBook) const
{
    std::string idxStr;
    int nbrOfCopies = (COLUMN_WIDTH * TOTAL_COLUMNS) + TOTAL_COLUMNS + 1;
    int emptySlotWidth = COLUMN_WIDTH * (TOTAL_COLUMNS - 1) + (TOTAL_COLUMNS / 2);

    phoneBookHeaderPrinter();
    for (int idx = 0; idx < MAX_CONTACTS; idx++)
    {
        idxStr = idx + 48 + 1;
        oneColumnPrinter(idxStr);
        const Contact *contact = phoneBook.getContact(idx);
        if (contact)
            contactDetailsAsARowPrinter(*contact);
        else
        {
            std::cout
            << edgeLayout << std::string(emptySlotWidth, emptySlot);
        }
        std::cout << edgeLayout << std::endl;
        std::cout << edgeLayout << std::string(nbrOfCopies - 2, lineDivision)
        << edgeLayout << std::endl;
    }
    std::cout << " " << std::string(nbrOfCopies - 2, tailLayout) << " " << std::endl;
}

#include "PhoneBook.hpp"
#include "Printers.hpp"

int main()
{
    PhoneBook phonebook;
    Printers printer;

    phonebook.addContact("John", "Doe", "JoD", "123-456-7890", "Loves pizza");
    phonebook.addContact("Jane", "Smith", "JayS", "987-654-3210", "Hates spiders");

    printer.phoneBookPrinter(phonebook);

    return 0;
}

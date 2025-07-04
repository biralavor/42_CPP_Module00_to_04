#include "PhoneBook.hpp"
#include "Printers.hpp"

int main()
{
    PhoneBook phonebook;
    Printers printer;

    phonebook.addContact("1John", "Doe", "JoD", "123-456-7890", "Loves pizza");
    phonebook.addContact("2Jane", "Smith", "JayS", "987-654-3210", "Hates spiders");
    phonebook.addContact("3Bob", "Johnson", "BobJ", "555-555-5555", "Afraid of heights");
    phonebook.addContact("4Alice", "Williams", "AliW", "444-444-4444", "Loves cats");
    phonebook.addContact("5Charlie", "Brown", "CharB", "333-333-3333", "Collects stamps");
    phonebook.addContact("6Eve", "Davis", "EveD", "222-222-2222", "Enjoys hiking");
    phonebook.addContact("7Frank", "Miller", "FrankM", "111-111-1111", "Plays guitar");
    phonebook.addContact("8Grace", "Wilson", "GraceW", "000-000-0000", "Loves painting");
    phonebook.addContact("9Hank", "Moore", "HankM", "123-123-1234", "Enjoys cooking");

    printer.phoneBookPrinter(phonebook);
    phonebook.searchContact(3);

    return 0;
}

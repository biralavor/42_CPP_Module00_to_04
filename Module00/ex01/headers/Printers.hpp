#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook;
class Contact;

class Printers
{
public:
    void columnPrinter(const std::string &str) const;
    void contactDetailsPrinter(const Contact &contact) const;
    void headerPrinter() const;
    void phoneBookPrinter(const PhoneBook &phoneBook) const;
};

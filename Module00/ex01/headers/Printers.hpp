#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook;
class Contact;

class Printers
{
public:
    void oneColumnPrinter(const std::string &str) const;
    void contactDetailsAsARowPrinter(const Contact &contact) const;
    void contactDetailsAsAColumnPrinter(int idx, const Contact &contact) const;
    void headerPrinter() const;
    void phoneBookPrinter(const PhoneBook &phoneBook) const;
};

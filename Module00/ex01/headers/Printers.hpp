#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook;
class Contact;

class Printers
{
public:
    void oneColumnCenteredPrinter(const std::string &str) const;
    void oneColumnPrinter(const std::string &str) const;
    void contactDetailsAsARowPrinter(const Contact &contact) const;
    void contactDetailsAsAColumnPrinter(int idx, const Contact &contact) const;
    void phoneBookHeaderPrinter() const;
    void searchContactHeaderPrinter() const;
    void phoneBookPrinter(const PhoneBook &phoneBook) const;
};

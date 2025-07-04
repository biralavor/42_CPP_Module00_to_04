#pragma once
#include <iostream>
#include <string>

class Contact
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact(std::string firstName, std::string lastName,
        std::string nickName, std::string phoneNumber,
        std::string darkestSecret);
    ~Contact(void);
    std::string getName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};
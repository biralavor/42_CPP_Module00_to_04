#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName,
    std::string nickName, std::string phoneNumber,
    std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

Contact::~Contact(void)
{
    std::cout
    << "Contact " << this->firstName << " " << this->lastName << " is being destroyed."
    << std::endl;
}

std::string Contact::getName() const
{
    return this->firstName + " " + this->lastName;
}

std::string Contact::getNickName() const
{
    return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}


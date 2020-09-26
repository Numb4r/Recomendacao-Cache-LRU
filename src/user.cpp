#include "user.hpp"
#include <iostream>
#include "Constants.hpp"

User::User(std::vector<string> vec)
    : userID(vec[0]), gender(vec[1]), age(vec[2]), occupation(vec[3]), zipCode(vec[4])
{
}
void User::imprimir()
{
    std::cout
        << userID
        << ":" << gender
        << ":" << this->age.c_str()
        << ":" << this->occupation.c_str()
        << ":" << zipCode << std::endl;
}
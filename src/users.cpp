#include "users.hpp"
#include <iostream>
#include "Constants.hpp"

User::User(std::initializer_list<string> init)
{

    auto it = init.begin();
    UserID = *it;
    ++it;
    Gender = *it;
    ++it;
    Age = *it;
    ++it;
    Occupation = *it;
    ++it;
    ZipCode = *it;
    std::cout
        << UserID
        << ":" << Gender
        << ":" << this->Age.c_str()
        << ":" << this->Occupation.c_str()
        << ":" << ZipCode << std::endl;
}

User::User(std::vector<string> vec)
    : UserID(vec[0]), Gender(vec[1]), Age(vec[2]), Occupation(vec[3]), ZipCode(vec[4])
{
    std::cout
        << UserID
        << ":" << Gender
        << ":" << this->Age.c_str()
        << ":" << this->Occupation.c_str()
        << ":" << ZipCode << std::endl;
}
void User::imprimir()
{
    std::cout
        << UserID
        << ":" << Gender
        << ":" << this->Age.c_str()
        << ":" << this->Occupation.c_str()
        << ":" << ZipCode << std::endl;
}
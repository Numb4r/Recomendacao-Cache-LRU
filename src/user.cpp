#include "user.hpp"
#include <cstring>
// #include <iostream>
// #include "Constants.hpp"
User MakeUser(const char *text, const char *tokens)
{
    User u;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);
    u.UserID = pch;

    pch = strtok(NULL, tokens);
    u.Gender = pch;

    pch = strtok(NULL, tokens);

    u.Age = pch;
    pch = strtok(NULL, tokens);

    u.Occupation = pch;
    pch = strtok(NULL, tokens);
    u.ZipCode;
    return u;
}
// User::User(std::vector<string> vec)
//     : userID(vec[0]), gender(vec[1]), age(vec[2]), occupation(vec[3]), zipCode(vec[4])
// {
// }
// void User::imprimir()
// {
//     std::cout
//         << userID
//         << ":" << gender
//         << ":" << this->age.c_str()
//         << ":" << this->occupation.c_str()
//         << ":" << zipCode << std::endl;
// }
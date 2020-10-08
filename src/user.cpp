#include "user.hpp"
#include <cstring>
#include <iostream>

User MakeUser(const char *text, const char *tokens)
{
    User u;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);
    u.UserID = new char[strlen(pch)+1];
    strcpy(u.UserID,pch);
    

    pch = strtok(NULL, tokens);
    u.Gender = new char[strlen(pch)+1];
    strcpy(u.Gender,pch);
    

    pch = strtok(NULL, tokens);
    u.Age = new char[strlen( pch)+1];
    strcpy(u.Age,pch);

    pch = strtok(NULL, tokens);
    u.Occupation = new char[strlen(pch)+1];
    strcpy(u.Occupation,pch);

    pch = strtok(NULL, tokens);
    u.ZipCode = new char[strlen(pch)+1];
    strcpy(u.ZipCode,pch);
    return u;
}
void PrintUser(const User user){
    std::cout
    << "UserID: "<< user.UserID<<" "
    << "\nGender: "<< user.Gender<<" "
    << "\nAge: "<< user.Age<<" "
    << "\nOccupation: "<< user.Occupation<<" "
    << "\nZipCode: "<< user.ZipCode<<std::endl;
}
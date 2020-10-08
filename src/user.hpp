#pragma once
struct User
{
    char *UserID;
    char *Gender;
    char *Age;
    char *Occupation;
    char *ZipCode;
};
User MakeUser(const char *text, const char *tokens);
void PrintUser(const User user);
    
#include "user.hpp"
#include <cstring>

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
    u.ZipCode = pch;
    return u;
}

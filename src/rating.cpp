#include "rating.hpp"
#include <iostream>
#include <cstring>
// Rating::Rating(std::vector<string> vec) : userId(vec[0]), movieId(vec[1]), rating(vec[2]), timeStamp(vec[3])
// {
// }
// void Rating::imprimir() const
// {
//     std::cout << movieId << "." << userId << "." << rating << "." << timeStamp << std::endl;
// }
// Rating::Rating(const char *text, const char *tokens)
// {
//     char str[strlen(text) + 1];
//     strcpy(str, text);

//     char *pch = strtok(str, ":");

//     movieId = pch;
//     pch = strtok(NULL, ":");
//     userId = pch;

//     pch = strtok(NULL, ":");

//     rating = pch;
//     pch = strtok(NULL, ":");

//     timeStamp = pch;
//     std::cout << movieId << "." << userId << "." << rating << "." << timeStamp << std::endl;
// }
Rating MakeRating(const char *text, const char *tokens)
{
    Rating r;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);

    r.movieId = pch;
    pch = strtok(NULL, tokens);
    r.userId = pch;

    pch = strtok(NULL, tokens);

    r.rating = pch;
    pch = strtok(NULL, tokens);

    r.timeStamp = pch;
    return r;
}
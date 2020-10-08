#include "rating.hpp"
#include <iostream>
#include <cstring>

Rating MakeRating(const char *text, const char *tokens)
{
    Rating r;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);
    r.movieId = new char[strlen(pch)+1];
    strcpy(r.movieId,pch);
    pch = strtok(NULL, tokens);
    r.userId = new char[strlen(pch)+1];
    strcpy(r.userId,pch);

    pch = strtok(NULL, tokens);
    r.rating = new char[strlen(pch)+1];
    strcpy(r.rating,pch);
    pch = strtok(NULL, tokens);
    r.timeStamp = new char[strlen(pch)+1];
    strcpy(r.timeStamp,pch);
    return r;
}
void PrintRating(const Rating rating){
     std::cout
    << "MovieID: "      << rating.movieId<<" "
    << "\nUserId: "     << rating.userId<<" "
    << "\nRating: "     << rating.rating<<" "
    << "\ntimeStamp: "  << rating.timeStamp
    <<std::endl;
}
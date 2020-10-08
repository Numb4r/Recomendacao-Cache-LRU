#include <string>
#include <vector>
#pragma once
struct Rating
{
    char *userId;
    char *movieId;
    char *rating;
    char *timeStamp;
};
Rating MakeRating(const char *text, const char *tokens);
void PrintRating(const Rating rating);

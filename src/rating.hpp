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
// using string = std::string;
// class Rating
// {
// private:
//     string userId;
//     string movieId;
//     string rating;
//     string timeStamp;

// public:
//     Rating(/* args */) = default;
//     Rating(const char *text, const char *tokens);
//     Rating(std::vector<string> vec);
//     void imprimir() const;
// };

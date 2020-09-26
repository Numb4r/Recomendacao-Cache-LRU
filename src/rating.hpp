#include <string>
#include <vector>
#pragma once
using string = std::string;
class Rating
{
private:
    string userId;
    string movieId;
    string rating;
    string timeStamp;

public:
    Rating(/* args */) = default;
    Rating(std::vector<string> vec);
    void imprimir() const;
};

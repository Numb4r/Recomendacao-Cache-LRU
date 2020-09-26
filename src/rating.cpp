#include "rating.hpp"
#include <iostream>
Rating::Rating(std::vector<string> vec) : userId(vec[0]), movieId(vec[1]), rating(vec[2]), timeStamp(vec[3])
{
}
void Rating::imprimir() const
{
    std::cout << movieId << "." << userId << "." << rating << "." << timeStamp << std::endl;
}
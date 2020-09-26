#include "movie.hpp"
#include <iostream>
Movie::Movie(std::vector<string> vec) : MovieId(vec[0]), Title(vec[1]), Genres(vec[2])
{
}
void Movie::imprimir() const
{
    std::cout << MovieId << "." << Title << "." << Genres << "." << std::endl;
}
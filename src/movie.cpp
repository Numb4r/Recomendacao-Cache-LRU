#include "movie.hpp"
#include <cstring>
Movie MakeMovie(const char *text, const char *tokens)
{
    Movie m;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);

    m.MovieId = pch;
    pch = strtok(NULL, tokens);
    m.Title = pch;

    pch = strtok(NULL, tokens);

    m.Genres = pch;
    return m;
}
// #include <iostream>
// Movie::Movie(std::vector<string> vec) : MovieId(vec[0]), Title(vec[1]), Genres(vec[2])
// {
// }
// void Movie::imprimir() const
// {
//     std::cout << MovieId << "." << Title << "." << Genres << "." << std::endl;
// }
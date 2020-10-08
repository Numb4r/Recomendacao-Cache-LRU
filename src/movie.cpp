#include "movie.hpp"
#include <iostream>
#include <cstring>
Movie MakeMovie(const char *text, const char *tokens)
{
    Movie m;
    char str[strlen(text) + 1];
    strcpy(str, text);

    char *pch = strtok(str, tokens);

    m.MovieId = new char[strlen(pch)+1];
    strcpy(m.MovieId,pch);
    pch = strtok(NULL, tokens);
    m.Title = new char[strlen(pch)+1];
    strcpy(m.Title,pch);

    pch = strtok(NULL, tokens);
    m.Genres = new char[strlen(pch)+1];
    strcpy(m.Genres,pch);
    return m;
}
void PrintMovie(const Movie movie){
    std::cout
    << "MovieID: "      << movie.MovieId<<" "
    << "\nTitle: "      << movie.Title<<" "
    << "\nGenres: "     << movie.Genres<<" "
    <<std::endl;
}

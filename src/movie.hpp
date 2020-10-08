#pragma once
struct Movie
{
    char *MovieId;
    char *Title;
    char *Genres;
};
Movie MakeMovie(const char *text, const char *tokens);
void PrintMovie(const Movie movie);

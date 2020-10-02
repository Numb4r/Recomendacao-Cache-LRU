// #include <string>
// #include <vector>
#pragma once
struct Movie
{
    char *MovieId;
    char *Title;
    char *Genres;
};
Movie MakeMovie(const char *text, const char *tokens);
// using string = std::string;
// class Movie
// {
// private:
//     string MovieId;
//     string Title;
//     string Genres;

// public:
//     Movie() = default;
//     void imprimir() const;
//     Movie(std::vector<string> vec);
// };

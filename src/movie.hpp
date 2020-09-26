#include <string>
#include <vector>
using string = std::string;
class Movie
{
private:
    string MovieId;
    string Title;
    string Genres;

public:
    Movie() = default;
    void imprimir() const;
    Movie(std::vector<string> vec);
};

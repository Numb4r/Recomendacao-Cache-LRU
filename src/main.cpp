#include <iostream>
#include <cstring>
#include "user.hpp"
#include "movie.hpp"
#include "rating.hpp"
#include "list.hpp"
#include <fstream>
int main(int argc, char const *argv[])
{

        List<User> listUser;
    List<Rating> listRating;
    List<Movie> listMovie;

    std::ifstream file{"/home/yuri/Studies/C_C++/Recomendacao-Cache-LRU/ml-1m/ratings.dat"};
    std::cout << file.good() << std::endl;
    std::string s;
    while (file >> s)
    {

        listRating.push_back(MakeRating(s.c_str(), ":"));
    }
    file.close();
    file.open("/home/yuri/Studies/C_C++/Recomendacao-Cache-LRU/ml-1m/users.dat");
    std::cout << file.good() << std::endl;

    while (file >> s)
    {
        listUser.push_back(MakeUser(s.c_str(), ":"));
    }
    file.close();
    file.open("/home/yuri/Studies/C_C++/Recomendacao-Cache-LRU/ml-1m/movies.dat");
    std::cout << file.good() << std::endl;

    while (file >> s)
    {
        listMovie.push_back(MakeMovie(s.c_str(), ":"));
    }
    return 0;
}

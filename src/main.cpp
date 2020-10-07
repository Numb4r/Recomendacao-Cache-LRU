#include <iostream>
#include "user.hpp"
#include "movie.hpp"
#include "rating.hpp"
#include "list.hpp"
#include "fileIO.hpp"
#include <functional>

int main()
{
    
    // std::function<User(const char*,const char*)> MU= MakeUser;
    // std::function<Rating(const char*,const char*)>MR = MakeRating;
    // std::function<Movie(const char*,const char*)>MM = MakeMovie;
   
    List<User>listUser(fillList<User>("ml-1m/users.dat",":", std::function<User(const char*,const char*)> (MakeUser)));
    List<Rating> listRating(fillList<Rating>("ml-1m/ratings.dat",":", std::function<Rating(const char*,const char*)> (MakeRating)));
    List<Movie> listMovie(fillList<Movie>("ml-1m/movies.dat",":", std::function<Movie(const char*,const char*)> (MakeMovie)));
    std::cout<<listUser.size()<< "-"<<listRating.size()<<"-"<<listMovie.size()<<std::endl;

  
    return 0;
}

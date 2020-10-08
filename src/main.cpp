#include <iostream>
#include "user.hpp"
#include "movie.hpp"
#include "rating.hpp"
#include "list.hpp"
#include "fileIO.hpp"
#include <functional>

int main()
{
       
    List<User>listUser(fillList<User>("ml-1m/users.dat",":", MakeUser));
    List<Rating> listRating(fillList<Rating>("ml-1m/ratings.dat",":", MakeRating));
    List<Movie> listMovie(fillList<Movie>("ml-1m/movies.dat",":", MakeMovie));
    std::cout<<listUser.size()<< "-"<<listRating.size()<<"-"<<listMovie.size()<<std::endl;
    
    // listUser.printFullList(PrintUser);
    // listRating.printFullList(PrintRating);
    // listMovie.printFullList(PrintMovie);
    

  
    return 0;
}

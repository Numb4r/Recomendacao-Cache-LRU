#include <iostream>
#include "Constants.hpp"
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{

    char *PATHFILES;
    strcpy(PATHFILES, argc > 0 ? argv[1] : "ml-1m");

    std::ifstream file{USERFILE};
    std::cout << file.is_open() << std::endl;
    std::string str;
    while (file >> str)
    {
        std::cout << str << std::endl;
    }

    return 0;
}

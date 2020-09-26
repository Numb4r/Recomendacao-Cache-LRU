#include "fileIO.hpp"
std::vector<char *> getInfoFile(const char *nameFile)
{
    std::vector<char *> vecAux;
    std::ifstream file{nameFile};
    char *lineFile;
    while (file.good())
    {
        file >> lineFile;
        vecAux.push_back(lineFile);
    }
    return std::move(vecAux);
}
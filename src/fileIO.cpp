#include "fileIO.hpp"
std::vector<std::string> getInfoFile(const char *nameFile)
{
    std::vector<std::string> vecAux;
    std::ifstream file{nameFile};
    std::string lineFile;
    while (file.good())
    {
        file >> lineFile;
        vecAux.push_back(lineFile);
    }
    return std::move(vecAux);
}
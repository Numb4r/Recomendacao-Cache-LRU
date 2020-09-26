#include <string>
#include <vector>
#include <regex>
/*A funcao deve receber como parametro a string a ser tokenizada e uma expressao regular*/
std::vector<std::string> tokenizacao(const std::string str, const char *regex)
{
    // std::vector<std::string> splitstr;
    // std::stringstream iss(str);
    // std::string intermediare;
    // while (std::getline(iss, intermediare, ':'))
    // {
    //     splitstr.push_back(intermediare);
    // };

    // auto iss = std::istringstream{str};
    // auto straux = std::string{};
    // while (iss >> straux)
    // {
    //     splitstr.push_back(straux);
    // }

    auto const re = std::regex{regex};
    std::vector<std::string> splitstr(
        std::sregex_token_iterator(str.begin(), str.end(), re, -1),
        std::sregex_token_iterator());
    return std::move(splitstr);
}
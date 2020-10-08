#include "list.hpp"
#include <fstream>
#include <functional>
template<typename T>
List <T> fillList(const char* fileName,const char* token,std::function<T(const char*,const char*)> MakerT){
    List<T> list;
    std::ifstream file{fileName};
    std::cout << file.good() << std::endl;
    std::string s;
    
    while (std::getline(file,s))
    {
        list.push_back(MakerT(s.c_str(), token));
    }
    file.close();
    return std::move(list);
}



#include "list.hpp"
#include <fstream>
#include <vector>
#include <functional>
#pragma once
// template<typename T>
// ctn::List <T> fillList(const char* fileName,const char* token,std::function<T(const char*,const char*)> MakerT){
//     ctn::List<T> list;
//     std::ifstream file{fileName};
//     std::cout << file.good() << std::endl;
//     std::string s;
    
//     while (std::getline(file,s))
//     {
//         list.push_back(MakerT(s.c_str(), token));
//     }
//     file.close();
//     return std::move(list);
// }
/*
TODO:
tentar uma list<list<rating[movieid,rating(pair?)]>> pra formar uma matriz de fatoracao
*(sem necessidade de carregar o arquivo de usuarios e filmes no primeiro momento)
cada linha sera um usuario
cada usuario tera uma lista (linha da matriz(item da lista mae)) que contem o id do filme e o rating(isso sera mais facil de achar o id do filme em questao)

(id,rating)

(20,5)  (30,3)  (500,1) (120,4)
(12,1)  (500,5) (40,3)  

*/
struct itemMatriz{
    unsigned int MovieId;
    float rating;
    itemMatriz()=default;
    itemMatriz(unsigned int MovieId,unsigned short rating):MovieId(MovieId),rating(rating){};
};
/*
std vector deixa 0.1s mais rapido
>problema na implementacao da ctn::List
*/
// std::vector<std::vector<itemMatriz>> MatrizFatoracao(const char* fileName){
//     std::vector<std::vector<itemMatriz>> list;
//     std::vector<itemMatriz> linha;

//     FILE* file;
//     if(!(file = fopen(fileName,"r"))){
//         std::cerr<<"Erro ao abrir o arquivo"<<std::endl;
//         return list;
//     }
//     int userAtual{},userComparacao{1},movieId{},dumb; 
//     float rating{};
//     while(!feof(file))
//     {   
//         fscanf(file,"%d::%d::%f::%d",&userAtual,&movieId,&rating,&dumb);
//         if(userAtual != userComparacao){
//             userComparacao = userAtual;
//             list.push_back(linha);
//             linha.clear();
//         }
//         linha.push_back(itemMatriz(movieId,rating));
//     }
//     list.push_back(linha);
//     fclose(file);
//     return std::move(list);
// }



ctn::List<ctn::List<itemMatriz>> MatrizFatoracao(const char* fileName){
    
    ctn::List<ctn::List<itemMatriz>> list;
    ctn::List<itemMatriz> linha;
    FILE* file;
    if(!(file = fopen(fileName,"r"))){
        std::cout<<"Erro ao abrir o arquivo"<<std::endl;
        exit(-1);
        
    }
    int userAtual{},userComparacao{1},movieId{},dumb; 
    float rating;
    while(!feof(file))
    {   
        fscanf(file,"%d::%d::%f::%d",&userAtual,&movieId,&rating,&dumb);
        if(userAtual != userComparacao){
            userComparacao = userAtual;
            list.push(std::move(linha));
            linha.clear();
        }        
        linha.push(itemMatriz(movieId,rating));
    }
    list.push(std::move(linha));
    fclose(file);
    return std::move(list);
}






ctn::List<itemMatriz> UserRatings(const char* fileName,const unsigned short minimoRating = 1){
    ctn::List<itemMatriz> user;
    FILE * file;
    if(!(file = fopen(fileName,"r"))){
        std::cerr<<"Error ao abrir o arquivo"<<std::endl;
        exit(-1);
        
    }
    int dumb{},movieId{};
    float rating{};
    while (!feof(file))
    {
        fscanf(file,"%d::%d::%f::%d",&dumb,&movieId,&rating,&dumb);
        if (rating >= minimoRating)
        {
            user.push(itemMatriz(movieId,rating));
        }
        
    }
    fclose(file);
    return std::move(user);
}


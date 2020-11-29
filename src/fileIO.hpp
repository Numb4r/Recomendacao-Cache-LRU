#pragma once
#include "list.hpp"
#include <map>
#include <cstring>
#include <fstream>

struct itemMatriz{
    unsigned int UserId;
    unsigned int MovieId;
    float rating;
    itemMatriz()=default;
    itemMatriz(unsigned int MovieId,unsigned short rating):MovieId(MovieId),rating(rating){};
    itemMatriz(unsigned int MovieId,unsigned short rating,unsigned int UserId):MovieId(MovieId),rating(rating),UserId(UserId){};

};

std::map<unsigned int,char*> MovieList(const char* fileName,const char* token = "::"){
    std::map<unsigned int,char*> filmes;
    std::ifstream file{fileName};
    std::string s;
    int id;
    char* name;
    while (std::getline(file,s))
    {
        
        char str[strlen(s.c_str()+1)];
        strcpy(str,s.c_str());
        char *pch = strtok(str,token);
        id = atoi(pch);
        pch = strtok(NULL,token);
        name = new char[strlen(pch)+1];
        strcpy(name,pch);
        filmes.insert({id,name});  
    }
    file.close();
    return std::move(filmes);
}
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
        linha.push(itemMatriz(movieId,rating,userAtual));
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

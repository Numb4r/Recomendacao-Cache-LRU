#pragma once
#include <cmath>
#include "fileIO.hpp"
#include "list.hpp"
#include "sorting.hpp"


struct euclidian_score
{
    ctn::List<itemMatriz> &linha;
    int numeroDeFilmesSimilares;
    int numeroDeFilmesDiferentes;
    float distance;
    euclidian_score(ctn::List<itemMatriz> &linha,int numeroDeFilmesSimilares,int numeroDeFilmesDiferentes ,float distance)
     : linha(linha),numeroDeFilmesSimilares(numeroDeFilmesSimilares),numeroDeFilmesDiferentes(numeroDeFilmesDiferentes),distance(distance){}    
     euclidian_score operator=(const euclidian_score& e){
         this->distance = e.distance;
         this->numeroDeFilmesDiferentes= e.numeroDeFilmesDiferentes;
         this->numeroDeFilmesSimilares = e.numeroDeFilmesSimilares;
         this->linha = e.linha;
     }
};
float score(euclidian_score &e){
    return ((e.numeroDeFilmesSimilares/(1+(1*e.distance)))/(1+(1*e.distance)));
}
/* 
TODO : Refatorar essa funcao com um metodo de ordenacao mais eficiente 
*/
ctn::Stack<euclidian_score> EncontrarKMelhoresUsuarios(ctn::List<euclidian_score> &Notas,int K){
    ctn::Queue<euclidian_score> aux;
    int min = score(Notas.head()->data);
    auto nd = Notas.head();
    auto indexMin = Notas.head();
    for (size_t i = 0; i < K; i++)
    {        
        aux.push(nd->data);
        if(score(nd->data) < min){
            min = score(nd->data);
            indexMin = aux.tail();
        }
        nd = nd->next;
    }
    for (auto i = nd; i != nullptr; i=i->next)
    {
        if(score(i->data) > min){
            min = score(i->data);
            indexMin->data = i->data;
            for (auto r = aux.head();r != nullptr;r=r->next)
            {
                if(score(r->data) < min){
                    min = score(r->data);
                    indexMin= r;
                }
            }
            
        }
    }
    
    sort::Selection<euclidian_score>(aux,[](euclidian_score var1,euclidian_score var2){
        return score(var1) < score(var2);
    });
    return aux.transfer<ctn::Stack<euclidian_score>>(K);
}

/*Essa funcao e mal otimizada ja que nao usa hashmap.Too bad */
                            /* @deprecated */
ctn::List<itemMatriz> EncontrarKMelhoresFilmes(ctn::List<euclidian_score> melhoresUsuarios,const int K = 20){
    ctn::List<itemMatriz> Filmes;
    for (auto i = melhoresUsuarios.head(); i != nullptr; i=i->next)
    {
        for (auto j = i->data.linha.head(); j != nullptr; j=j->next)
        {
            Filmes.push(j->data);
        }
        
    }
    sort::Selection<itemMatriz>(Filmes,[](itemMatriz v1,itemMatriz v2)->bool{
        return v1.MovieId > v2.MovieId;
    });
    ctn::List<itemMatriz> MelhoresFilmes;
    int filmeAtual = Filmes.front().MovieId;
    float totalValue{};
    
    for (auto i = Filmes.head(); i != nullptr; i=i->next)
    {
        if(i->data.MovieId == filmeAtual){
            
            totalValue+=i->data.rating;
            // std::cout<< i->data.rating << " = "<<totalValue<<std::endl;
        }else {

            // std::cout<<">"<<filmeAtual<<" - "<<totalValue<<std::endl;
            if (totalValue!=0)
                MelhoresFilmes.push(itemMatriz(filmeAtual,totalValue));
            totalValue = 0;
            filmeAtual=i->data.MovieId;
        }
    }
    sort::Selection<itemMatriz>(MelhoresFilmes,[](itemMatriz v1,itemMatriz v2){
        return v1.rating > v2.rating;
    });
    // MelhoresFilmes.show([](itemMatriz i){
    //     std::cout<<i.MovieId<<" - "<<i.rating<<std::endl;
    // });
    return MelhoresFilmes.transfer<ctn::List<itemMatriz>>(K);
}
/*=========================== @deprecated ===========================*/

/* Funcao com hashmap */

#include <map>
/*
FIX: 
- Existe uma PEQUENA chance do topo da pilha ser lixo de memoria quando usado o metodo Quicksort.
- Executando novamente corrige o problema
*/

ctn::List<itemMatriz> EncontrarKMelhoresFilmesH(ctn::List<euclidian_score> &melhoresUsuarios,ctn::List<itemMatriz> &User,const int &K = 20){
    std::map<int,float> notaFilmes,userFilmes;
    ctn::List<itemMatriz> melhoresFilmes;
    
    for (auto i = User.head() ; i != nullptr ; i=i->next)
    {
        userFilmes.insert({i->data.MovieId,i->data.rating});
            
    }
    auto media = [K](float nota,float indice)->float{return (nota/K)*indice;};
    int posicaoPilha{};

    for (auto i = melhoresUsuarios.head(); i != nullptr; i=i->next)
    {
        for (auto j = i->data.linha.head(); j != nullptr; j=j->next)
        {
            
            if (userFilmes.find(j->data.MovieId)==userFilmes.end())
            {
                if (notaFilmes.find(j->data.MovieId)!=notaFilmes.end())
                
                    notaFilmes.at(j->data.MovieId) += media(j->data.rating,posicaoPilha);       
                else
                    notaFilmes.insert({j->data.MovieId,media(j->data.rating,posicaoPilha)});
                
            }
        }
        posicaoPilha++;
    }
    itemMatriz *vet = new itemMatriz[notaFilmes.size()];
    int j{},max{},size_array{notaFilmes.size()};

    for (auto &&i : notaFilmes)
    {
        vet[j] = itemMatriz(i.first,i.second);
        max = vet[j].rating > max ? vet[j].rating : max;
        j++;
    }
    // sort::Quick<itemMatriz>(vet,0,size_array,[](itemMatriz t1,itemMatriz t2){
    //     return t1.rating >= t2.rating;
    // });
    sort::radixsort(vet,size_array,max);

    for (size_t i = size_array-1; i >size_array-K ; i--)
    {
        melhoresFilmes.push(vet[i]);   
    }
    return melhoresFilmes;

}
/*---------------------------------------------------------*/
/*
TODO:
Melhorara esse trecho com hashmap,retirando a necessidade do segundo for
*/

euclidian_score CalcularDistanciaEuclidiana(ctn::List<itemMatriz> &linha,ctn::List<itemMatriz> &User){
    int numeroDeFilmesSimilares{};
    long numeroDeFilmesDiferentes{};
    float distance{};
    for(auto i=linha.head();i!=linha.tail()->next;i=i->next)
    {
        auto data = i->data;
        for (auto k = User.head(); k != User.tail()->next; k=k->next)
        {
            if (data.MovieId == k->data.MovieId)
            {   
                distance+=pow((data.rating-k->data.rating),2);
                numeroDeFilmesSimilares++;
            }else{
                numeroDeFilmesDiferentes++;
            }
        } 
    } 
    distance= sqrt(distance);
    return std::move(euclidian_score(linha,numeroDeFilmesSimilares,numeroDeFilmesDiferentes,distance));
}

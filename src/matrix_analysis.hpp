#include <cmath>
#include "fileIO.hpp"
#include "list.hpp"
#include <vector>
/* Total score 
    Numero de filmes vistos similares / (1+(1*distancia))
*/

struct euclidian_score
{
    std::vector<itemMatriz> &linha;
    int numeroDeFilmesSimilares;
    float distance;
    euclidian_score(std::vector<itemMatriz> &linha,int numeroDeFilmes,float distance) : linha(linha),numeroDeFilmesSimilares(numeroDeFilmes),distance(distance){}
};


euclidian_score CalcularDistanciaEuclidiana(std::vector<itemMatriz> &linha,ctn::List<itemMatriz> &User){
    int numeroDeFilmesSimilares{};
    float distance{};
    for (auto &i : linha)
    {
        for (auto k = User.head(); k != User.tail()->next; k=k->next)
        {
            
            if (i.MovieId == k->data.MovieId)
            {   
                distance+=pow(static_cast<float>(i.rating-k->data.rating),2);
                numeroDeFilmesSimilares++;
                /*Debug*/
                // std::cout<<"\tMid: "<<i.MovieId<<" - "<<k->data.MovieId<<"\tR: "<<
                // i.rating<<" - "<<k->data.rating <<
                // "\tDistance: "<<distance<<
                // "\tNFilmesSimilares: "<<numeroDeFilmesSimilares<<std::endl;
            }
        } // k
    } // j   
    // std::cout<<"Distancia: "<<distance<<" - ";
    distance= sqrt(distance);
    // std::cout<<distance<<std::endl;
    // std::cout<<"Numero de filmes similares: "<<numeroDeFilmesSimilares << std::endl;

    return std::move(euclidian_score(linha,numeroDeFilmesSimilares,distance));
}
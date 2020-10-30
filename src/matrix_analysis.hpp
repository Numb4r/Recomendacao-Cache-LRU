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

ctn::Stack<euclidian_score> EncontrarKMelhoresUsuarios(ctn::List<euclidian_score> &Notas,int K){
    /* First Try */
    // sort::Selection<euclidian_score>(Notas,[](auto var1,auto var2)->bool{
    //     return score(var1) > score(var2);
    // });
    // return Notas.transfer<ctn::Stack<euclidian_score>>(K);
    /* Second Try */

    ctn::Queue<euclidian_score> aux;
    int min = score(Notas.head()->data);
    auto nd = Notas.head();
    auto indexMin = Notas.head();
    for (size_t i = 0; i < 20; i++)
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
        return score(var1) > score(var2);
    });
    return aux.transfer<ctn::Stack<euclidian_score>>(K);

}

// euclidian_score CalcularDistanciaEuclidiana(std::vector<itemMatriz> &linha,ctn::List<itemMatriz> &User){
//     int numeroDeFilmesSimilares{},numeroDeFilmesDiferentes;
//     float distance{};
//     /* Isso seria simplificado com hashmap
//     nao precisaria iterar a linha inteira,apenas verificar a existencia de um elemento de hash X na linha
//     */
//     for (auto &i : linha)
//     {
//         for (auto k = User.head(); k != User.tail()->next; k=k->next)
//         {
//             if (i.MovieId == k->data.MovieId)
//             {   
//                 distance+=pow((i.rating-k->data.rating),2);
//                 numeroDeFilmesSimilares++;
//             }else{
//                 numeroDeFilmesDiferentes++;
//             }
//         } // k
//     } // j   
//     distance= sqrt(distance);
//     return std::move(euclidian_score(linha,numeroDeFilmesSimilares,distance));
// }
euclidian_score CalcularDistanciaEuclidiana(ctn::List<itemMatriz> &linha,ctn::List<itemMatriz> &User){
    int numeroDeFilmesSimilares{};
    long numeroDeFilmesDiferentes{};
    float distance{};
    /* Isso seria simplificado com hashmap
    nao precisaria iterar a linha inteira,apenas verificar a existencia de um elemento de hash X na linha
    */
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
        } // k
    } // j   
    distance= sqrt(distance);
    return std::move(euclidian_score(linha,numeroDeFilmesSimilares,numeroDeFilmesDiferentes,distance));
}

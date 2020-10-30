#include <iostream>
#include "fileIO.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "matrix_analysis.hpp"
#define MATRIXFILENAME  "ml-1m/ratings.dat"
#define USERFILENAME    "ml-1m/dumb_user.dat"
#define K 20
using Matrix = ctn::List<ctn::List<itemMatriz>> ;
/*
score =((i.numeroDeFilmesSimilares/(1+(1*i.distance)))/(1+(1*i.distance)))
*/
int main(int argc, char const *argv[])
{
    
    const char* fileUserPath= argc >= 2 ? argv[1] : USERFILENAME;
    
    // // std::vector<std::vector<itemMatriz>> o {MatrizFatoracao(MATRIXFILENAME)}; // 0.1s/0.2s mais rapido
    Matrix MatrixDeFatoracao{MatrizFatoracao(MATRIXFILENAME)} ;
    ctn::List<itemMatriz> User{UserRatings(fileUserPath)};
        
    ctn::List<euclidian_score> Notas;
    for (auto i = MatrixDeFatoracao.head(); i != MatrixDeFatoracao.tail()->next; i=i->next)
    {
        Notas.push(CalcularDistanciaEuclidiana(i->data,User));
    }
    ctn::Stack<euclidian_score> PilhaMelhoresUsuarios{EncontrarKMelhoresUsuarios(Notas,K)};
    PilhaMelhoresUsuarios.show([](euclidian_score i){
        std::cout<<i.linha.front().UserId<<" - "<<i.numeroDeFilmesSimilares<<" - " <<i.numeroDeFilmesDiferentes<<" - "<< score(i)<<std::endl;
    });
    
    return 0;
}

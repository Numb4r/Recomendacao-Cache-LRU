#include <iostream>
#include "fileIO.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "matrix_analysis.hpp"
#include "Timer.hpp"
#include <map>
#define MATRIXFILENAME  "ml-1m/ratings.dat"
#define MOVIESFILENAME  "ml-1m/movies.dat"
#define USERFILENAME    "ml-1m/dumb_user.dat"
#define K 20
using Matrix = ctn::List<ctn::List<itemMatriz>> ;
#include "sorting.hpp"
int main(int argc, char const *argv[])
{  
    const char* fileUserPath= argc >= 2 ? argv[1] : USERFILENAME;
    // std::map<int,const char*> movies = MovieListHash(MOVIESFILENAME);
    Timer t;
    Matrix MatrixDeFatoracao{MatrizFatoracao(MATRIXFILENAME)} ;
    t.ShowResult("Construcao da matriz de fatoracao");
    ctn::List<itemMatriz> User{UserRatings(fileUserPath)};
    ctn::List<euclidian_score> Notas;
    t.Reset();
    for (auto i = MatrixDeFatoracao.head(); i != MatrixDeFatoracao.tail()->next; i=i->next)
    {
        Notas.push(CalcularDistanciaEuclidiana(i->data,User));
    }
    t.ShowResult("Calculo da distancia euclidiana");
    t.Reset();
    
    ctn::Stack<euclidian_score> PilhaMelhoresUsuarios{EncontrarKMelhoresUsuarios(Notas,K)};
    t.ShowResult("Encontrando os K melhores usuarios");
    PilhaMelhoresUsuarios.show([](euclidian_score i){
        std::cout<<i.linha.front().UserId<<" - "<<i.numeroDeFilmesSimilares<<" - " <<i.numeroDeFilmesDiferentes<<" - "<< score(i)<<std::endl;
    });
    
    t.Reset();
    auto filmes= EncontrarKMelhoresFilmesH(PilhaMelhoresUsuarios,User,K);
    t.ShowResult("Encontrar os K Melhores filmes por hash");
    filmes.show([](itemMatriz i){
        std::cout<<i.MovieId<<" - "<<i.rating<<std::endl;
    });


    return 0;
}

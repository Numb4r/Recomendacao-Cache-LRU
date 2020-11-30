#include <iostream>
#include "Timer.hpp"
#include "fileIO.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "matrix_analysis.hpp"
#include "sorting.hpp"
#include "hashmap.hpp"
#include "cache.hpp"
#include <map>
#define MATRIXFILENAME  "ml-1m/ratings.dat"
#define MOVIESFILENAME  "ml-1m/movies.dat"
#define USERFILENAME    "ml-1m/dumb_user.dat"
#define K 20
using Matrix = ctn::List<ctn::List<itemMatriz>> ;
char* fileUserPath{USERFILENAME};
int cacheSize{};
void argumentsCapture(const char** argv,int argc){
    for (size_t i = 1; i < argc; i++)
    {
        if (strcmp("-userfile",argv[i])==0)
        {
            fileUserPath = new char[strlen(argv[i+1]+1)]();
            strcpy(fileUserPath,argv[i+1]);
            i++;
        }else if (strcmp("-cachesize",argv[i])==0){
            cacheSize=atoi(argv[i+1]);
            i++;   
        }
    }
}
int main(int argc, char const *argv[])
{  
    argumentsCapture(argv,argc);

    std::map<unsigned int,char*> filmesListNames = MovieList(MOVIESFILENAME);
    ctn::List<itemMatriz> User{UserRatings(fileUserPath)};
    ctn::List<euclidian_score> Notas;
    Timer t;



    Matrix MatrixDeFatoracao{MatrizFatoracao(MATRIXFILENAME)} ;
    t.ShowResult("Construcao da matriz de fatoracao");


    



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
    ctn::Queue<itemMatriz> filmes= EncontrarKMelhoresFilmes(PilhaMelhoresUsuarios,User,K);
    t.ShowResult("Encontrar os K Melhores filmes por hash");
    filmes.show([filmesListNames](itemMatriz i){
        std::cout<<filmesListNames.at(i.MovieId)<< " - " << i.rating<<std::endl;
    });



    Cache c_LRU = CreateCache(
        User, /* Lista de filmes do usuario (key)*/
        filmes, /* Lista melhores filmes (valor)*/
        (cacheSize==0 ? User.size() : cacheSize) /* Tamanho maximo da cache */
    );
    
    

    std::cout<<"\n\tCache LRU"<<std::endl;
    /* Testes */
    std::cout<<"Cache max size:"<<c_LRU.maxSize()<<std::endl;
    std::cout<<"Cache size:"<<c_LRU.cache.size()<<std::endl;
    
    
    c_LRU.getItem(594);
    

    c_LRU.insertCache(1,filmes,true);
    std::cout<<"Cache size apos a insercao,verificando um possivel estouro da capacidade e aplicando a politica LRU:"<<c_LRU.cache.size()<<std::endl;
    auto aux = c_LRU.getItem(1);
    std::cout<<"Verificando se foi adicionado a key mostrando o ultimo filme:"<<filmesListNames.at(aux.back().MovieId)<<std::endl;
    std::cout<<"Verificando se ouve a remocao da entrada menos utilizada:"<<(c_LRU.cache.find(594)==c_LRU.cache.end() ? "" :"nao")<<"removido"<<std::endl;//hardcoded


    return 0;
}

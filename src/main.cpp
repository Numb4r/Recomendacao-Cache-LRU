#include <iostream>
#include "Timer.hpp"
#include "fileIO.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "matrix_analysis.hpp"
#include "cache.hpp"
#include <map>
#include <vector>
#define MATRIXFILENAME  "ml-1m/ratings.dat"
#define MOVIESFILENAME  "ml-1m/movies.dat"
#define USERFILENAME    "ml-1m/dumb_user.dat"
#define K 20
using Matrix = ctn::List<ctn::List<itemMatriz>> ;
char* fileUserPath{USERFILENAME};
int cacheSize{};
std::map<unsigned int,char*> filmesListNames = MovieList(MOVIESFILENAME);
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





std::vector<int> verificaCache(ctn::List<itemMatriz> &UserEntry,Cache &c_LRU){
    std::vector<int> listFilmesNaCache;
    ctn::List<itemMatriz> newUser;
    
    for (auto i = UserEntry.head(); i !=nullptr; i=i->next)
    {
        auto item{c_LRU.getItem(i->data.MovieId)};
        if(item != nullptr ) {
            
            listFilmesNaCache.push_back(i->data.MovieId);
            
            
        }else
        {
            newUser.push(i->data);
        }
        
    }
        

    if (newUser.size() > 0)
    {
        UserEntry.clear();
        

        for (auto i = newUser.head(); i !=nullptr; i=i->next)
        {
            UserEntry.push(i->data);
        }
    }
    
        
    
    return listFilmesNaCache;
}







 ctn::Queue<itemMatriz> computarUsuario(ctn::List<itemMatriz> &UserEntry,Matrix &MatrixFatoracao,Cache &c_LRU){
    std::map<int,int> mapaFilmesMatrizAtual;
    if (c_LRU.size()!=0)
    {
        std::vector<int> listFilmesNaCache(verificaCache(UserEntry,c_LRU));
        for (auto &&i :listFilmesNaCache )
            for(auto j = c_LRU.getItem(i)->filmes.head();j!=nullptr;j=j->next )
                if(mapaFilmesMatrizAtual.find(j->data.MovieId) == mapaFilmesMatrizAtual.end())
                    mapaFilmesMatrizAtual.insert({j->data.MovieId,j->data.rating});
                else if (mapaFilmesMatrizAtual.at(j->data.MovieId) < j->data.rating)
                    mapaFilmesMatrizAtual.at(j->data.rating) = j->data.rating;
    }
    

    ctn::List<euclidian_score> Notas;
    for (auto i = MatrixFatoracao.head(); i != MatrixFatoracao.tail()->next; i=i->next)
    {
        Notas.push(CalcularDistanciaEuclidiana(i->data,UserEntry));    
    }
    ctn::Stack<euclidian_score> PilhaMelhoresUsuarios{EncontrarKMelhoresUsuarios(Notas,K)};
    ctn::Queue<itemMatriz> filmes= EncontrarKMelhoresFilmes(PilhaMelhoresUsuarios,UserEntry,mapaFilmesMatrizAtual,K);

     
    // filmes.show([](itemMatriz i){
    //     std::cout<<filmesListNames.at(i.MovieId)<< " - " << i.rating<<std::endl;
    
    // });




    
    if (c_LRU.size()==0)
    {
        c_LRU = CreateCache(
            UserEntry, /* Lista de filmes do usuario (key)*/
            filmes, /* Lista melhores filmes (valor)*/
            (cacheSize==0 ? UserEntry.size() : cacheSize) /* Tamanho maximo da cache */
        );
    }else
    {
        if(UserEntry.size() > 0)
            for (auto i = UserEntry.head(); i != nullptr; i=i->next)
            {
                
                c_LRU.insertCache(
                    i->data.MovieId, /*Lista de filmes do usuario (key) */
                    filmes /* Lista melhores filmes  (valor) */
                );
            }
    }
    return filmes;
    
}











int main(int argc, char const *argv[])
{  
    
    argumentsCapture(argv,argc);
    
    
    ctn::List<itemMatriz> User{UserRatings(fileUserPath)};
    ctn::List<euclidian_score> Notas;
    Cache c_LRU;
    Timer t;
    Matrix MatrixDeFatoracao{MatrizFatoracao(MATRIXFILENAME)} ;



    computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar sem cache: ");
    
    User.push(itemMatriz(3,4));
    User.push(itemMatriz(7,4));
    User.push(itemMatriz(6,4));
    User.push(itemMatriz(4,4));
    User.push(itemMatriz(20,4));



    t.Reset();
    computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar com cache: ");

    User.push(itemMatriz(10,4));



    t.Reset();
    computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar com cache: ");


    User.push(itemMatriz(20,4));

    t.Reset();
    computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar com cache: ");

    User.push(itemMatriz(11,4));

    t.Reset();
    computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar com cache: ");

    User.push(itemMatriz(13,4));

    t.Reset();
    auto filmes = computarUsuario(User,MatrixDeFatoracao,c_LRU);
    t.ShowResult("Tempo para executar com cache: ");
    
    std::cout<<"Cache size: "<<c_LRU.size()<<std::endl;
    
    
    
    
    return 0;
}

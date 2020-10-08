# Algoritimo de Recomendacao Utilizando Cache LRU
## Compile
```
make clean
make
make run
```
# Base de dados
Foi utilizado para teste uma base de dados sintetica disponibilizada pela grouplens da Univesity of Minnesota. Para fazer download dela clique [aqui](http://files.grouplens.org/datasets/movielens/ml-1m.zip).

Extraia ela na raiz do programa.
Para a documentacao da base veja [DOC](), ou seja a propria documentacao da base de dados.
```
Recomendacao-Cache-LRU
 ┣ ml-1m
 ┃ ┣ README
 ┃ ┣ movies.dat
 ┃ ┣ ratings.dat
 ┃ ┗ users.dat
 ┣ src
 ┃ ┣ source
 ┣ .gitignore
 ┣ LICENSE
 ┣ Makefile
 ┣ Readme.md
 
```
## Utilizando outra base de dados
Para se usar uma outra base e necessario uma modelagem especifica para ela.
Essa modelagem devera conter uma struct e uma funcao que sera responsavel pelo preenchimento da struct.
Essa funcao de preenchimento devera ter como parametro uma `string` e o token e devera retornar a struct preenchida.
### Exemplo:
```
struct Pessoa{
    string nome,
    string idade
};
Pessoa MakePessoa(const char* str,const char* token){
    Pessoa p;
    /* foo */
    return p;
}
```
Apos isso, sera possivel utilizar a funcao `fillList` que fara a montagem da lista.
A funcao fillList tem como parametro o caminho do arquivo,o token e um std::function que e construida pela funcao `Make` da struct.
```
List<typeStruct> list(fillList("path","tk",std::function<typeStruct(const char*,const char*)>)(MakeStruct));
```
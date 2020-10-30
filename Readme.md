# Algoritimo de Recomendacao Utilizando Cache LRU
## Compile
```
make clean
make
make run
```
# Base de dados
Foi utilizado para teste uma base de dados sintetica disponibilizada pela grouplens da University of Minnesota. Para fazer download dela clique [aqui](http://files.grouplens.org/datasets/movielens/ml-1m.zip).

Extraia ela na raiz do programa.
Para a documentacao nao oficial da base veja [DOC](https://github.com/Numb4r/Recomendacao-Cache-LRU/blob/master/Doc.md).
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


## Criando um usuario para testes

Para criar um usuario de testes deve se seguir o mesmo padrao do arquivo `rating.dat` da base de dados (UserID::MovieID::Rating::Timestamp).
Para usar o arquivo basta colocar na mesma pasta que a base de dados com o nome de `dumb_user.dat`, ou passar como parametro de inicializacao do programa.


# Documentacao base de dados
Essa documentacao e referente a base de dados da University of Minnesota usada de teste na construcao do algoritimo.
Isso e apenas uma pequena traducao da documentacao oficial fornecida, respeitando a clausula de nao redistribuicao da base sem a devida autorizacao.

A base de dados pode ser baixada [aqui](http://files.grouplens.org/datasets/movielens/ml-1m.zip).

O token usado nessa base e `:`

Para mais detalhes confira a documentacao oficial da base.
## User
>UserID::Gender::Age::Occupation::Zip-code
- Gender e denotado por "M" para masculino e "F" para feminino

- Age e dada no seguinte formato:
	*  1:  "Abaixo 18"
	* 18:  "18-24"
	* 25:  "25-34"
	* 35:  "35-44"
	* 45:  "45-49"
	* 50:  "50-55"
	* 56:  "56+"

- Occupation e dado no seguinte formato:

	*  0:  "other" or not specified
	*  1:  "academic/educator"
	*  2:  "artist"
	*  3:  "clerical/admin"
	*  4:  "college/grad student"
	*  5:  "customer service"
	*  6:  "doctor/health care"
	*  7:  "executive/managerial"
	*  8:  "farmer"
	*  9:  "homemaker"
	* 10:  "K-12 student"
	* 11:  "lawyer"
	* 12:  "programmer"
	* 13:  "retired"
	* 14:  "sales/marketing"
	* 15:  "scientist"
	* 16:  "self-employed"
	* 17:  "technician/engineer"
	* 18:  "tradesman/craftsman"
	* 19:  "unemployed"
	* 20:  "writer"
## Movie
>MovieID::Title::Genres
- Titles sao identidos ao nomes providos pelo site IMDB (incluindo ano de lancamento)
- Genres sao separados por pipe ( `|` ) e sao dados pelos seguintes generos:
	* Action
	* Adventure
	* Animation
	* Children's
	* Comedy
	* Crime
	* Documentary
	* Drama
	* Fantasy
	* Film-Noir
	* Horror
	* Musical
	* Mystery
	* Romance
	* Sci-Fi
	* Thriller
	* War
	* Western

- Alguns MovieIDs nao correspondem a um filme devido a uma entrada duplicada por acidente e/ou entradas de teste
- Essa arquivo foi preenchido a mao, erros e inconsistencias podem existir
## Rating
>UserID::MovieID::Rating::Timestamp
- UserIDs vao de 1 ate 6040
- MovieIDs vao de 1 a 3952
- Ratings sao feitos pela escala 5 estrela (sem ter meia estrela de avaliacao)
- Timestamp e representado em segundos desde o `"epoch"` retornada pelo time(2)
- Cada usuario tem pelo menos 20 avaliacoes (ratings)

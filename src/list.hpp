#include <vector>
#include <string>
#include <cstring>
// #include <stringstream>
#include <sstream>
#include "users.hpp"

template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *previous;
};
/*
Essa lista e uma lista encabecada
Gastara um pouco mais de memoria ao custo de nao precisar verificar se e uma lista vazia a cada adicao
Ou seja,seu indice internamente se inicia em 1;
*/
/*
Essa lista e inversamente linkada tambem,pra ficar mais facil a remocao por tras
*/
/*
Eu deveria usar smart pointer para o problema de alocacao
mas nao irei,pq e mais divertido ver meu eu do futuro sofrer com memory leak
*/
template <typename T>
class List
{
private:
    int length{0};
    node<T> *HEAD;
    node<T> *TAIL;
    node<T> *iterator;

public:
    node<T> *head();
    node<T> *tail();
    int size();
    void push_back(T data);
    void pop_back();
    // void push_front(T data);
    // void pop_front();
    List();
    List(const std::vector<std::string> infoArray, const char *tokens);
    // ~List();
};
template <typename T>
List<T>::List()
{
    node<T> *Node = new node<T>();
    Node->data = T();
    Node->next = nullptr;
    Node->previous = nullptr;
    HEAD = Node;
    TAIL = Node;
    ++length;
}
template <typename T>
void List<T>::push_back(const T data)
{
    node<T> *Nd = new node<T>();
    // if (!())
    // {
    //     throw "ERROR: CANNOT ALLOCATE MEMORY";
    //     return;
    // }
    Nd->data = data;
    TAIL->next = Nd;
    Nd->previous = TAIL;
    TAIL = Nd;
    ++length;
}
template <typename T>
void List<T>::pop_back()
{
    node<T> *Nd = TAIL;
    TAIL = TAIL->previous;
    delete Nd;
    --length;
}

template <typename T>
int List<T>::size()
{
    return length;
}
template <typename T>
node<T> *List<T>::head()
{
    return HEAD->next;
}
template <typename T>
node<T> *List<T>::tail()
{
    return TAIL;
}
template <typename T>
List<T>::List(const std::vector<std::string> infoVec, const char *tokens)
{
}
template <>
List<user>::List(const std::vector<std::string> infoVec, const char *tokens) : List<user>()
{

    /*
    TODO: TROCAR ESSA MERDA POR REGEX OU AWK PUTA Q PARIU CODIGO FEIO DO KRL
    */
    for (auto &&i : infoVec)
    {
        user us;
        std::vector<std::string> tokens;
        std::stringstream check(i);
        std::string intermediante;
        while (getline(check, intermediante, ':'))
        {
            tokens.push_back(intermediante);
        }
        us.UserID = tokens[0].c_str();
        us.Gender = tokens[1].c_str();
        us.Age = tokens[2].c_str();
        us.Occupation = tokens[3].c_str();
        us.ZipCode = tokens[4].c_str();
        tokens.clear();
        this->push_back(us);
    }
}
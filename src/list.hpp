/*
>Essa lista e uma lista encabecada,ou seja,seu indice internamente se inicia em 1;
>Essa lista e inversamente linkada 
*/
/*
Eu deveria usar smart pointer para o problema de alocacao
mas nao irei,pq e mais divertido ver meu eu do futuro sofrer com memory leak
*/

template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *previous;
};
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
    List();
    ~List();
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
}
template <typename T>
void List<T>::push_back(const T data)
{
    node<T> *Nd = new node<T>();
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
List<T>::~List()
{
    while (TAIL != nullptr)
    {
        this->pop_back();
    }
}
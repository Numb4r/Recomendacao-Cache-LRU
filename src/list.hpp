#pragma once
#include <functional>
#include <iostream>
/*
>Essa lista e uma lista encabecada
>Essa lista e duplamente encadeada
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

public:
    node<T> *head();
    node<T> *tail();
    int size() const;
    void printFullList(std::function<void(const T)>printfunc) const;
    void push_back(T data);
    void pop_back();
    List();
    // prevent shallow copy
    List(const List &obj); //Copy constructor
    List(List &&obj); //Move constructor
    // List<T> &operator=(const List &obj); //Copy assignment
    // List<T> &operator=(const List &&obj); //Move assignment

    // List<T> &operator=(const List &obj){
    //     if(this != &obj){
    //         delete HEAD;
    //         delete TAIL;
    //         HEAD = new node<T>(obj.HEAD);
    //         TAIL = new node<T>(obj.TAIL);
    //         length = obj.length;
    //     }
    //     return *this;

    // }

    // List<T> &operator=(const List &&obj){
    //     if(this != &obj){
    //         delete HEAD;
    //         delete TAIL;
    //         HEAD = obj.HEAD;
    //         TAIL = obj.TAIL;
    //         length = obj.length;
    //     }
    //     return *this;
    // }
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
    // PrintUser(data);
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
int List<T>::size() const
{
    return length;
}
template< typename T>
void List<T>::printFullList(std::function<void(const T)> printfunc) const{
    node <T> *nd = HEAD->next;
    while (nd!=nullptr)
    {
        printfunc(nd->data);
        nd = nd->next;
    }
    

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
//Shallow Copy prevent
template <typename T>
List<T>::List(const List<T> &obj){
    
    HEAD = new node<T>(*obj.HEAD);
    TAIL = new node<T>(*obj.TAIL);
    length = obj.length;
}
template <typename T>
List<T>::List( List<T> &&obj){
    HEAD = obj.HEAD;
    TAIL = obj.TAIL;
    obj.HEAD = nullptr;
    obj.TAIL = nullptr;
    length = obj.length;
}

template <typename T>
List<T>::~List()
{
    while (TAIL != nullptr)
    {
        this->pop_back();
    }
}
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
    int size() const{
        return length;
    }
    void printFullList(std::function<void(const T)>printfunc) const{
        node <T> *nd = HEAD->next;
        while (nd!=nullptr)
        {
            printfunc(nd->data);
            nd = nd->next;
        }
    }
    void push_back(T data){
    
        node<T> *Nd = new node<T>();
        Nd->data = data;
        TAIL->next = Nd;
        Nd->previous = TAIL;
        TAIL = Nd;
        ++length;
    }
    void pop_back(){
        node<T> *Nd = TAIL;
        TAIL = TAIL->previous;
        delete Nd;
        --length;
    }
    List(){
        node<T> *Node = new node<T>();
        Node->data = T();
        Node->next = nullptr;
        Node->previous = nullptr;
        HEAD = Node;
        TAIL = Node;
    }
    /*
    TODO : Consetar copy constructor/assignment
    */
    // prevent shallow copy
    List(const List &obj) //Copy constructor
    {
        std::cout<<"&obj"<<std::endl;
        HEAD = new node<T>(*obj.HEAD);
        TAIL = new node<T>(*obj.TAIL);
        length = obj.length;
    }
    List(List &&obj) //Move constructor
    {
        std::cout<<"&&obj"<<std::endl;
        
        HEAD = obj.HEAD;
        TAIL = obj.TAIL;
        obj.HEAD = nullptr;
        obj.TAIL = nullptr;
        length = obj.length;
    }
     List<T> &operator=(const List &obj){//Copy assignment
        std::cout<<"&obj"<<std::endl;

        if(this != &obj){
            delete HEAD;
            delete TAIL;
            HEAD = new node<T>(obj.HEAD);
            TAIL = new node<T>(obj.TAIL);
            length = obj.length;
        }
        return *this;

    }

    List<T> &operator=(const List &&obj){//Move assignment
        std::cout<<"&&obj"<<std::endl;

        if(this != &obj){
            delete HEAD;
            delete TAIL;
            HEAD = obj.HEAD;
            TAIL = obj.TAIL;
            length = obj.length;
        }
        return *this;
    }
    ~List(){
        while (TAIL != nullptr)
        {
            this->pop_back();
        }
    }
};





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
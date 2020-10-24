#pragma once
#include <iostream>
#include <functional>

template <typename T>
struct node
        {
            T data;
            struct node *next;
            struct node *previous;
        };
namespace ctn
{
    template <typename T>
    class List
    {
    protected:
        int length{0};
        node<T> *HEAD;
        node<T> *TAIL;

    public:
        node<T> *head();
        node<T> *tail();
        int size() const{
            return length;
        }
        /*
        TODO:Corrigir essa funcao quando a classe Stack faz o call
        */
        void printElements(std::function<void(const T)>printfunc) const{
            node <T> *nd = HEAD;
            while (nd=nd->next , nd != TAIL->next){printfunc(nd->data);}
        }
        virtual void push(T data){
        
            node<T> *Nd = new node<T>();
            Nd->data = data;
            TAIL->next = Nd;
            Nd->previous = TAIL;
            TAIL = Nd;
            ++length;
        }
        virtual void pop(){
            node<T> *Nd = TAIL;
            TAIL = TAIL->previous;
            delete Nd;
            length--;
        }
        void clear(){
            while (TAIL != HEAD)
            {
                this->pop();
            }
        }
        T front(){
            return HEAD->next->data;
        }
        T back(){
            return TAIL->data;
        }
        bool operator==(const List &obj){
            return this->HEAD == obj.HEAD && this->TAIL == obj.TAIL ? true : false;
        }
        bool operator!=(const List &obj){
            return this->HEAD == obj.HEAD && this->TAIL == obj.TAIL ? false : true;
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
            HEAD = obj.HEAD;
            TAIL = obj.TAIL;
            obj.HEAD = nullptr;
            obj.TAIL = nullptr;
            length = obj.length;
        }

         List<T> &operator=(const List &obj){//Copy assignment
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
                this->pop();
            }
        }
    };

} // namespace ctn






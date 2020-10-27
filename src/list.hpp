#pragma once
#include <iostream>
#include <functional>

template <typename T>
struct node
        {
            T data;
            struct node *next;
            struct node *previous;
            node(T data,struct node *previous,struct node *next) : data(data),previous(previous),next(next){}
            node() = default;
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
        node<T> *head(){
            return HEAD->next;
        }
        node<T> *tail(){
            return TAIL;
        }
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
        virtual void push(const T data){
            TAIL->next = new node<T>(data,TAIL,nullptr);
            TAIL = TAIL->next;
            ++length;
        }
        virtual void pop(){
            node<T> *Nd = TAIL;
            TAIL = TAIL->previous;
            delete Nd;
            length--;
        }
        void clear(){
            std::cout<<"Clear\n";
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
            node<T> *Node = new node<T>(T(),nullptr,nullptr);
            HEAD = TAIL = Node;
        }
        // prevent shallow copy
        List(const List &obj) //Copy constructor
        {
            std::cout<<"&obj\n";
            if (obj.HEAD == nullptr || obj.HEAD->next == nullptr)
            {
                std::cout<<"Empty\n";
                List();
            }else{
                HEAD = new node<T>(*obj.HEAD);
                node<T> *nd = obj.HEAD->next;
                node<T> *ndlist= HEAD;
                while (nd != obj.TAIL->next)
                {
                    // std::cout<<nd->data<<"\n";
                    ndlist->next = new node<T>(nd->data,ndlist,nullptr);
                    ndlist = ndlist->next;
                    nd = nd->next;

                }
                TAIL = ndlist;
                length = obj.length;
                
            }
            
        }
        List(List &&obj) //Move constructor
        {      
            std::cout<<"&&obj"<<std::endl;

            HEAD = obj.HEAD;
            TAIL = obj.TAIL;
            obj.HEAD = obj.TAIL = nullptr;
            length = obj.length;
        }

         List<T> &operator=(const List &obj){//Copy assignment
            std::cout<<"&obj\n";
            if(this != &obj){
                while (TAIL != nullptr)
                {
                    this->pop();
                }
                
                if (obj.HEAD == nullptr || obj.HEAD->next == nullptr)
                {
                    std::cout<<"Empty\n";
                    List();
                }else{
                    HEAD = new node<T>(*obj.HEAD);
                    node<T> *nd = obj.HEAD->next;
                    node<T> *ndlist= HEAD;
                    while (nd != obj.TAIL->next)
                    {
                        // std::cout<<nd->data<<"\n";
                        ndlist->next = new node<T>(nd->data,ndlist,nullptr);
                        ndlist = ndlist->next;
                        nd = nd->next;

                    }
                    TAIL = ndlist;
                    length = obj.length;
                    
                }
            }
            return *this;
        }

        List<T> &operator=(const List &&obj){//Move assignment
        std::cout<<"&&obj\n";
            if(this != &obj){
                while (TAIL != nullptr)
                {
                    this->pop();
                }
                HEAD = obj.HEAD;
                TAIL = obj.TAIL;
                length = obj.length;
            }
            return *this;
        }
        ~List(){
            std::cout<<"~List()"<<std::endl;
            while (TAIL != nullptr)
            {
                node<T> *Nd = TAIL;
                TAIL = TAIL->previous;
                delete Nd;
            }
        }
    };
      
} // namespace ctn







#pragma once
#include <iostream>
#include <functional>

template <typename T>
struct node
        {
            T data;
            struct node *next;
            struct node *previous;
            node(T data,struct node *previous = nullptr,struct node *next = nullptr) : data(data),previous(previous),next(next){}
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
            return HEAD;
        }
        node<T> *tail(){
            return TAIL;
        }
        int size() const{
            return length;
        }
        void show(std::function<void(const T)>printfunc,int NumeroLinhas = 0) const{
                node <T> *nd = HEAD;
            if(NumeroLinhas != 0)
                while (nd != nullptr && NumeroLinhas>0){printfunc(nd->data);nd=nd->next;NumeroLinhas--;}
            else
                while (nd != nullptr){printfunc(nd->data);nd=nd->next;}
        }
        virtual void push(const T data){

            if(isEmpty()){
                HEAD = TAIL = new node<T>(data);
            }else{
                TAIL->next = new node<T>(data,TAIL,nullptr);
                TAIL = TAIL->next;
            }
                
                ++length;
        }
        template<typename TypeCtn>
        TypeCtn transfer(int N){          
            TypeCtn aux;
            node<T> *nd = this->HEAD;
            while (nd!=nullptr && N > 0)
            {
                aux.push(nd->data);
                nd = nd->next;
                N--;
            }
            return std::move(aux);
        }
        bool isEmpty(){
            return HEAD==nullptr||TAIL==nullptr;
        }
        virtual void pop(){
            if (TAIL!=nullptr)
            {
                node<T> *Nd = TAIL;
                TAIL = TAIL->previous;
                delete Nd;
                Nd = nullptr;
                if(TAIL==nullptr)
                    HEAD=nullptr;
                length--;
            }
            
        }
        void clear(){
            while (HEAD!=nullptr)
            {
                node<T> *nd = HEAD;
                HEAD = HEAD->next;
                delete nd;
                nd = nullptr;
                length--;
            }
            
            HEAD = TAIL = nullptr;
            
        }
        T front(){
            return HEAD->data;
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

        List():HEAD(nullptr),TAIL(nullptr),length(0){}
        // prevent shallow copy
        List(const List &obj) //Copy constructor
        {
            if (obj.HEAD == nullptr)
            {
                HEAD = TAIL = nullptr;
            }else{
                HEAD = new node<T>(*obj.HEAD);
                node<T> *nd = obj.HEAD->next;
                node<T> *ndlist= HEAD;
                while (nd != obj.TAIL->next)
                {
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
            HEAD = obj.HEAD;
            TAIL = obj.TAIL;
            obj.HEAD = obj.TAIL = nullptr;
            length = obj.length;
        }

         List<T> &operator=(const List &obj){//Copy assignment
            if(this != &obj && obj.HEAD != nullptr){
                clear();
                HEAD = new node<T>(*obj.HEAD);
                node<T> *nd = obj.HEAD->next;
                node<T> *ndlist= HEAD;
                while (nd != obj.TAIL->next)
                {
                    ndlist->next = new node<T>(nd->data,ndlist,nullptr);
                    ndlist = ndlist->next;
                    nd = nd->next;
                }
                TAIL = ndlist;
                length = obj.length;
            }
            return *this;
        }

        List<T> &operator=(const List &&obj){//Move assignment
            if(this != &obj && obj.HEAD != nullptr){
                clear();
                HEAD = obj.HEAD;
                TAIL = obj.TAIL;
                obj.HEAD = obj.TAIL = nullptr;
                length = obj.length;
            }
            return *this;
        }
        ~List(){
           clear();
        }
    };
      
} // namespace ctn







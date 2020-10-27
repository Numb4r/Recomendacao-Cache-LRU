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
        /*
        TODO:Corrigir essa funcao quando a classe Stack faz o call
        */
        void show(std::function<void(const T)>printfunc) const{
            node <T> *nd = HEAD;
            while (nd=nd->next , nd != TAIL->next){printfunc(nd->data);}
        }
        /*
        1 - First item
        0 - n item
        -1 - error
        */
        virtual bool push(const T data){

            if(isEmpty()){
                HEAD = TAIL = new node<T>(data);
                std::cout<<"Is emtpy,first\n";
                ++length;

                return 1;
            }else{
                TAIL->next = new node<T>(data,TAIL,nullptr);
                TAIL = TAIL->next;
                std::cout<<"Not empty "<<(TAIL->previous==HEAD ? 1 : 0)<<"\n";
                ++length;

                return 0;
            }
                
        }
        
        bool isEmpty(){
            return HEAD==nullptr||TAIL==nullptr;
        }
        virtual bool pop(){
            if (TAIL!=nullptr)
            {
                // std::cout<<"not Empty(pop) : "<<(TAIL==HEAD ? 1 : 0)<<"\t";
                node<T> *Nd = TAIL;
                TAIL = TAIL->previous;
                delete Nd;
                Nd = nullptr;
                if(TAIL==nullptr)
                    HEAD=nullptr;
                // std::cout<<(TAIL==nullptr ? 1 : 0)<<"\n";
                length--;
                return 0;
            }
            return 1;
        }
        void clear(){
            
            while (TAIL!=nullptr)
            {
                node<T>* nd = TAIL;
                TAIL = TAIL->previous;
                delete nd;  
                nd = nullptr;
                length--; 
            }
            
            HEAD = TAIL = nullptr;
            
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

        List():HEAD(nullptr),TAIL(nullptr),length(0){
            std::cout<<"Default()\n"<<
            (HEAD==nullptr ? 1 : 0) << "-"<< (TAIL==nullptr ? 1 : 0 )<<"\n";

        }
        // prevent shallow copy
        List(const List &obj) //Copy constructor
        {
            std::cout<<"&obj\n";
            if (obj.HEAD == nullptr)
            {
                std::cout<<"Empty\n";
                HEAD = TAIL = nullptr;
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
            if(this != &obj && obj.HEAD == nullptr){
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
            std::cout<<"&&obj\n";
            if(this != &obj){
                clear();
                HEAD = obj.HEAD;
                TAIL = obj.TAIL;
                length = obj.length;
            }
            return *this;
        }
        ~List(){
           clear();
        }
    };
      
} // namespace ctn







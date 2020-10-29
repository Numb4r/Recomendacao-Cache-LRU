#pragma once
#include "list.hpp"

namespace ctn
{
    template <typename T>
    class Stack : public List<T>
    {
    public:
        void push(const T data)override {
            if(this->isEmpty()){
                this->HEAD = this->TAIL = new node <T>(data);
            }else
            {
                this->HEAD->previous = new node<T>(data,nullptr,this->HEAD)    ;
                this->HEAD = this->HEAD->previous;
            }
            this->length++;
        }
        void pop()override{
            if(this->HEAD!=nullptr){
                node<T> *nd = this->HEAD;
                this->HEAD = this->HEAD->next;
                delete nd;
                nd = nullptr;
                if(this->HEAD==nullptr)
                    this->TAIL=nullptr;    
                this->length--;
                
            }
        }
        
    };

} // namespace ctn

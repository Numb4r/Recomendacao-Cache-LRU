#pragma once 
#include <functional>
#include "list.hpp"

namespace ctn
{
    template <typename T>
    class Queue : public List<T>
    {
    public:
        Queue() : List<T>() {}
        void push(const T data) override{
            
            this->TAIL->next = new node<T>;
            this->TAIL->next->next=T();
            this->TAIL->next->data = data;
            this->TAIL = this->TAIL->next;
            this->length++;
        }
        void pop() override{
            node<T> *n = this->HEAD->next;
            this->HEAD->next = this->HEAD->next->next;
            this->length--;
            delete n;
        }
        
    };


} // namespace ctn


#pragma once
#include "list.hpp"

namespace ctn
{
    template <typename T>
    class Stack : public List<T>
    {
    public:
        Stack() : List<T>(){}
        void push(const T data)override {
            node<T> *n = new node<T>;
            n->data = data;
            n->next = this->HEAD->next;
            this->HEAD->next = n;
            this->length++;
        }
        void pop()override{
            node<T> *n = this->HEAD->next;
            this->HEAD->next = this->HEAD->next->next;
            this->length--;
            delete n;
        }
        
    };

} // namespace ctn

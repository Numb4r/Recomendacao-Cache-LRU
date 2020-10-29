#pragma once 
#include "list.hpp"

namespace ctn
{
    template <typename T>
    class Queue : public List<T>
    {
    public:
        void pop() override{
            node<T> *n = this->HEAD;
            this->HEAD = this->HEAD->next;
            this->length--;
            delete n;
            n = nullptr;
        }
        
    };
} // namespace ctn

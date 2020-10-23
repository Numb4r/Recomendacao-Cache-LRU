
#pragma once
#include <functional>
#include <iostream>
template  <typename T>
struct nodeStack{
    T data;
    struct nodeStack * next;
};
template <typename T>
class Stack
{
private:
    nodeStack<T> *HEAD;
    nodeStack<T> *TAIL;
    size_t size{0};
public:
    Stack(){
        nodeStack<T> *n = new nodeStack<T>;
        n->data = T();
        n->next = nullptr;
        HEAD = n;
        TAIL = n;
    }
    void print(std::function<void(const T)> f){
        nodeStack<T> *n = HEAD->next;
        while (n!=nullptr)
        {
            f(n->data);
            n = n->next;
        }
        
    }
     /*
    TODO : implementar copy/move constructor/assignment
    */
    ~Stack(){
        nodeStack<T> *n = HEAD;
        do
        {
            HEAD = HEAD->next;
            delete n;
            n = HEAD;
        } while (n!=nullptr);
        std::cout<<"~stack()"<<std::endl;
    }
    void push(const T data){
        nodeStack<T> *n = new nodeStack<T>;
        n->data = data;
        n->next = HEAD->next;
        HEAD->next = n;
    }
    void pop(){
        nodeStack<T> *n = HEAD->next;
        HEAD->next = HEAD->next->next;
        size--;
        delete n;
    }
    T front(){
        return HEAD->next->data;
    }
    T back(){
        return TAIL->data;
    }
    // T operator=(*this){
    //     T data = this->HEAD->next.data;
    //     this->pop();
    //     return data;
    // }
};

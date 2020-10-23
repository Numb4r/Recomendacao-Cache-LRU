#pragma once 
#include <functional>
template  <typename T>
struct nodeQueue{
    T data;
    struct nodeQueue * next;
};
template <typename T>
class Queue
{
private:
    nodeQueue<T> *HEAD;
    nodeQueue<T> *TAIL;
    size_t size{0};
public:
    Queue(){
        nodeQueue<T> *n = new nodeQueue<T>;
        n->data = T();
        n->next = nullptr;
        HEAD = n;
        TAIL = n;
    }
    /*
    TODO : implementar copy/move constructor/assignment
    */
    ~Queue(){
        nodeQueue<T> *n = HEAD;
        do
        {
            HEAD = HEAD->next;
            delete n;
            n = HEAD;
        } while (n!=nullptr);
    }
    void print(std::function<void(const T)> f){
          nodeQueue<T> *n = HEAD->next;
        while (n!=nullptr)
        {
            f(n->data);
            n = n->next;
        }
    }
    void push(const T data){
        TAIL->next = new nodeQueue<T>;
        TAIL->next->next=T();
        TAIL->next->data = data;
        TAIL = TAIL->next;
        size++;
    }
    void pop(){
        nodeQueue<T> *n = HEAD->next;
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
    // T operator=(){
    //     T data =  HEAD->next->data;
    //     this->pop();
    //     return data;
    // }
    
};


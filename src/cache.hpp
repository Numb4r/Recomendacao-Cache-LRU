#pragma once 
#include "fileIO.hpp"
#include "queue.hpp"
#include <map>
#include "hashmap.hpp"
class Cache;
struct C_Item{
    private:
        int _counter;
    public:
    ctn::Queue<itemMatriz> filmes;
    int counter()const{return _counter;}
    C_Item()=default;
    C_Item(ctn::Queue<itemMatriz> filmes):filmes(filmes),_counter(1){}
    friend class Cache;
};
class Cache
{
private:
    // ctn::Map<int,C_Item> cache;
    unsigned short MAXTAM{20};
public:
    std::map<int,C_Item> cache;
    void insertCache(int key,ctn::Queue<itemMatriz> filmes,bool debug = false){
        C_Item item{filmes} ;
        
        if(cache.size()>=MAXTAM){
                int p {this->LRU()};
                if(debug)        
                    std::cout<<"removido:"<<p<<std::endl;
        }
        if (cache.find(key)==cache.end())
        {
            this->cache.insert({key,filmes});
        }else
        {
            cache.at(key)=filmes;
        }
        
        
    }
    std::map<int,C_Item>::const_iterator invalidEntry()const{
        return cache.end();
    }
    unsigned short maxSize()const {
        return MAXTAM;
    }
    unsigned short size() const{
        return cache.size();
    }
    C_Item * getItem(int key){
        // auto item{&cache.find(key)->second};
        auto item{cache.find(key)};
        if (item != cache.end())
        {
            item->second._counter++;
            return &(item->second);
        }else
        {
            return nullptr;
        }
        
        

        // if(item->counter()!=0)
            // item->_counter++;
        // return *item;
        // return ctn::Queue<itemMatriz>();
        // auto item {cache.find(key)};
        // if(item != cache.nodeEmpty())
        //     item->value.counter++;
        // return item->value.filmes;
    }
    int LRU(){
        auto key{cache.begin()->first};
        int counterMenorItem{cache.begin()->second.counter()};
        for (auto &&i : cache)
        {
            if (i.second.counter() < counterMenorItem)
            {
                key = i.first;
                counterMenorItem = i.second.counter();
            }
            i.second._counter=1;   
        }
        auto r { cache.find(key)->first};
        cache.erase(cache.find(key));
        return r;
    }
    Cache() = default;
    Cache(unsigned short TAM):MAXTAM(TAM){}
    
};
Cache CreateCache(ctn::List<itemMatriz> UserBase,ctn::Queue<itemMatriz> filmes,const short size = 20){
    Cache cache(size);
    for (auto i = UserBase.head(); i !=nullptr; i=i->next)
    {
        cache.insertCache(i->data.MovieId,filmes);
    }
    return cache;
}

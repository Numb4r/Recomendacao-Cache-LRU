#pragma once 
#include "fileIO.hpp"
#include "queue.hpp"
#include <map>
#include "hashmap.hpp"
struct C_Item{
    ctn::Queue<itemMatriz> filmes;
    int counter;
    C_Item()=default;
    C_Item(ctn::Queue<itemMatriz> filmes):filmes(filmes),counter(1){}
};
class Cache
{
private:
    // ctn::Map<int,C_Item> cache;
    unsigned short MAXTAM{20};
public:
    std::map<int,C_Item> cache;
    void insertCache(int key,ctn::Queue<itemMatriz> filmes,bool debug = 0){
        C_Item item{filmes} ;
        // this->cache.insert(key,filmes);
        if(cache.size()>=MAXTAM){
                int p {this->LRU()};
                if(debug)        
                    std::cout<<"removido:"<<p<<std::endl;
        }
        this->cache.insert({key,filmes});
    }
    ctn::Queue<itemMatriz>& getItem(int key){
        auto item{&cache.find(key)->second};
        if(item->counter!=0)
            item->counter++;
        return item->filmes;
        // auto item {cache.find(key)};
        // if(item != cache.nodeEmpty())
        //     item->value.counter++;
        // return item->value.filmes;
    }
    int LRU(){
        auto key{cache.begin()->first};
        int counterMenorItem{cache.begin()->second.counter};
        for (auto &&i : cache)
        {
            if (i.second.counter < counterMenorItem)
            {
                key = i.first;
                counterMenorItem = i.second.counter;
            }
            i.second.counter=0;   
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

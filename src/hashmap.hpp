#include <initializer_list>
#pragma once
    template <typename TKey,typename TValue>
    struct H_item
    {
        TKey key;
        TValue value;
        struct H_item *next; // colisoes
        H_item()=default;
        H_item(const TKey key,TValue value):key(key),value(value){}
    };
namespace ctn
{
    template <typename TKey,typename TValue,int hashCount = 100000>
    class Map
    {
        private:
            H_item<TKey,TValue> ** table; 
            H_item<TKey,TValue> *empty;
            unsigned long hashFunction(const TKey &key) const{
                unsigned long int value{key};
                return value % hashCount;
            }
        public:
            bool isEmpty()const{
                for (size_t i = 0; i < hashCount; i++)
                {
                    if(table[i]!=empty){
                        return false;
                    }
                }
                return true;
            }
            void insert(TKey key,TValue value)const{
                unsigned long hash{hashFunction(key)};               
                if (table[hash]== empty)
                {
                    table[hash]=  new H_item<TKey,TValue>(key,value);
                }else
                {
                    H_item<TKey,TValue>* i = table[hash];
                    while (i->next != nullptr)
                    {
                        i=i->next;
                    }
                    i->next = new H_item<TKey,TValue>(key,value);      
                }
            }
            TValue at(const TKey &key){
                auto item = table[hashFunction(key)];
                while (item->key != key) 
                {
                    item = item->next;
                }
                return item->value;
            }
            H_item<TKey,TValue> *find(const TKey &key){                
                if (table[hashFunction(key)]!= this->empty)
                {
                    return table[hashFunction(key)];
                }
                return empty;
            }
            H_item<TKey,TValue> *nodeEmpty() const{
                return empty;
            }
            void remove(const TKey key) const noexcept{
                auto hash = hashFunction(key);
                if (this->table[hash] != empty)
                {
                    H_item<TKey,TValue>* item = this->table[hash];
                    H_item<TKey,TValue>* anterior;
                    while (item!=nullptr && item->key != key)
                    {
                        anterior = item;
                        item=item->next;
                    }
                    if (item != nullptr)
                    {
                        anterior->next = item->next;
                        delete item;
                        item = nullptr;
                    }

                    // delete table[hash];
                    // table[hash] = empty;
                }
                
            }
            // void insert(std::initializer_list<std::H_item<TKey,TValue>> list){
            //     Tkey key;
            //     Tvalue value;
            //     for (auto &&i : list)
            //     {
                    
            //     }
                
            // }
            
            Map(){
                this->table = new H_item<TKey,TValue>*[hashCount];
                this->empty = new H_item<TKey,TValue>();
                for (int i = 0; i < hashCount; i++)
                {
                    this->table[i] = empty;
                }
            }
            ~Map(){
                for (int i = 0; i < hashCount; i++)
                {
                    if(table[i]!=empty){
                        for (auto j = table[i]->next; j != nullptr;)
                        {
                            auto next = j->next;
                            delete j;
                            j = next;
                        }
                        delete table[i];
                        table[i] = nullptr;
                    }
                }
                delete empty;
                empty = nullptr;
                delete []table;
            }
    };
} // namespace ctn

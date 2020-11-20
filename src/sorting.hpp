#include "list.hpp"
#pragma once
template <typename T>
void swap(T &a,T &b){
    T aux{a};
    a = b;
    b = aux;
}
template <typename T>
int partition(T *array,int low,int high,std::function<bool(T var1,T var2)> cmpFunction){
    T pivot{array[high]};
    int i = (low -1);
    for (int j = low; j < high-1; j++)
    {
        if(cmpFunction(array[j],pivot)){
            i++;
            swap<T>(array[i],array[j]);
        }
    }
    swap<T>(array[i+1],array[high]);
    return (i+1);
}
namespace sort
{
    /*Uso especifico para o tipo ctn::List*/
   template<typename T>
    void Selection(ctn::List<T> &list,std::function<bool(T var1,T var2)> funcaoDeComparacao){
        for (auto i = list.head(); i != nullptr; i=i->next)
        {
            auto  jMin = i;
            for (auto j = i->next; j != nullptr; j=j->next)
            {   
                if(funcaoDeComparacao(j->data,jMin->data)){
                
                    jMin = j;
                }
            }
            if (jMin != i)
            {
                auto d  = i->data;
                i->data=jMin->data;
                jMin->data = d;
            }
        }  
    }
    template<typename T>
    void Selection(T *array,unsigned int size_array,std::function<bool(T var1,T var2)> cmpFunction){
        for (size_t i = 0; i < size_array-1; i++)
        {
            int jMin = i;               
            for (size_t j = i+1; j < size_array; j++)
            {
                if(cmpFunction(array[j],array[jMin])){
                    jMin = j;
                    
                }
            }
            if(jMin != i){
                swap<T>(array[i],array[jMin]);

            }
            
        }
    }
    template <typename T> 
    void Insertion(T *array,int size_array,std::function<bool(T v1,T v2)> cmpFunction){
        for (size_t i = 1; i < size_array; i++)
        {
            T key = array[i];
            int j = i -1;
            while (j>=0 && cmpFunction(array[j],key))
            {
                array[j+1] = array[j];
                j=j-1;
            }
            array[j+1] = key;

        }
        
    }

    template<typename T>
    void Quick(T *array,int low,int high,std::function<bool(T var1,T var2)> cmpFunction){
        if(low < high){
            int pi = partition<T>(array,low,high,cmpFunction);
            Quick(array,low,pi-1,cmpFunction);
            Quick(array,pi+1,high,cmpFunction);
        }
    }
    template <typename T>
    void Shell(T *array,int size_array,std::function<bool(T var1,T var2)> cmpFunction){
        for (size_t gap = size_array/2; gap > 0; gap/=2)
        {
            for (size_t i = gap; i < size_array; i++)
            {
                int j{};
                T temp = array[i];
                for (j = i; j >= gap && cmpFunction(array[j-gap],temp); j-=gap)
                    array[j] = array[j-gap];
                    
                array[j] = temp;
                
            }
        }
    }
} // namespace sort

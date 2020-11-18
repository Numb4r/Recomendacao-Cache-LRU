#include "list.hpp"
namespace sort
{
    template <typename T>
    void swap(T &a,T &b){
        T aux{a};
        a = b;
        b = aux;
    }
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
   

} // namespace sort

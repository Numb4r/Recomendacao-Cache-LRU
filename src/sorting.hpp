#include "list.hpp"
namespace sort
{
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
} // namespace sort

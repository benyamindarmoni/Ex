#pragma once
#include <iostream>

namespace itertools
{
    template <typename T1, typename T2>

    class zip 
    {
        private:
        T1 cont1;
        T2 cont2;
        
        public:
        
        zip(T1 start, T2 end1) : cont1(start), cont2(end1)
        {

        }
        
        template <typename P1, typename P2>

        class iterator
        {
          private:
            P1 ptr1; 
            P2 ptr2; 

            public:
          
            iterator(P1 p1, P2 p2) : ptr1(p1), ptr2(p2)
            {
            }

            
            std::pair<decltype(*ptr1), decltype(*ptr2)> operator*() const
            {
                return  std::pair<decltype(*ptr1), decltype(*ptr2)> (*ptr1 , *ptr2);
            }

            iterator<P1, P2>& operator++()
            {
                ++ptr1; 
                ++ptr2; 
			    return *this;
            }

          
		    bool operator!=(iterator<P1,P2> it)
            {
			    return (ptr1 != it.ptr1);
            }
        };

        public:
        auto begin() const
        {
            return iterator <decltype(cont1.begin()), decltype(cont2.begin())> (cont1.begin(), cont2.begin());
        }

        auto end() const
        {
            return iterator <decltype(cont1.end()), decltype(cont2.end())> (cont1.end(), cont2.end());
        }
    };
    
    template <typename T1,typename T2>
    ostream &operator<<(ostream &os, const std::pair<T1,T2> &c) 
    {
        os << c.first << "," << c.second;
        return os;
    }
}

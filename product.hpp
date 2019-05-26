#pragma once

namespace itertools
{
    template <typename T1, typename T2>

    class product 
    {
        private:
        T1 cont1;
        T2 cont2; 
        
        public:
  
        product(T1 _start, T2 _end) : _it1(_start), _it2(_end)
        {
        }
        
        template <typename P1, typename P2>
        class iterator
        {
            private:
            P1 ptr1; 
            P2 ptr2; 
            P2 help; 

            public:
            iterator(P1 p1, P2 p2) : ptr1(p1), ptr2(p2), help(p2)
            {
            }
            std::pair<decltype(*ptr1), decltype(*ptr2)> operator*() const
            {
                return  std::pair<decltype(*ptr1), decltype(*ptr2)> (*ptr1 , *ptr2);
            }
            iterator<P1, P2>& operator++()
            {
                ++ptr2; 
			    return *this;
            }

		    bool operator!=(iterator<P1,P2> it)
            {
                if (!(ptr2 != it.ptr2)) 
                {
                    ++ptr1;
                    ptr2 = help;
                }
			    return ((ptr1 != it.ptr1) && (ptr2 != it.ptr2)); 
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
}

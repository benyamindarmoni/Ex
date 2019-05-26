#pragma once

namespace itertools
{
    template <typename T1, typename T2>

    
    class chain 
    {
        protected:
        T1 cont1; 
        T2 cont2; 
        
        public:
        chain(T1 start, T2 end) : cont1(start), cont2(end)
	{
        }
        template <typename P1, typename P2>
        class iterator
        {
          private:
            P1 ptr1; 
            P2 ptr2; 
            bool isfirst; 

            public:
          
            iterator(P1 ptr_a, P2 ptr_b) : ptr1(ptr_a), ptr2(ptr_b), isfirst(true)
            {
            } 
            decltype(*ptr1) operator*() const
            {
                if (isfirst) 
                {
                    return *ptr1; 
                }
		    else
			    return *ptr2; 
            }

            iterator<P1, P2>& operator++()
            {
                if (isfirst)
                {
                    ++ptr1; 
                }
		    else
                ++ptr2;
                return *this;
            }

           
		    bool operator!=(iterator<P1,P2> it)
            {
                if (isfirst && !(ptr1 != it.ptr1)) 
                {
                    isfirst = false;
                }
                if (isfirst)
                {
                    return (ptr1 != it.ptr1); 
                }
                return (ptr2 != it.ptr2); 
            }
        };

        public:
        
        auto begin() const
        {
            return iterator <decltype(cont1.begin()), decltype(cont2.begin())> (cont1.begin(),cont2.begin());
        }

        
        auto end() const
        {
            return iterator <decltype(cont1.end()), decltype(cont2.end())> (cont1.end(), cont2.end());
        }

    };
}

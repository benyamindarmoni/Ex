#pragma once

namespace itertools
{

    template <typename T>
    
    class range
    {
        protected:
        T start; 
        T end1; 

        public:
        
        range(T first, T second) : start(first), end1(second)
        {

        }

        class iterator
        {
            private:
            T ptr; 

            public:
           
            iterator(T p) : ptr(p)
            {

            }

          
            T operator*() const
            {
			    return ptr;
            }

           
            iterator& operator++()
            {
                ++ptr;
			    return *this;
            }

		    bool operator==(const iterator& other) const
            {
			    return (ptr == other.ptr);
		    }

            
		    bool operator!=(const iterator& other)
            {
			    return (ptr != other.ptr);
            }
        };

        public:
       
        iterator begin() const
        {
		    return iterator(start);
	    }
	    iterator end() const
        {
		    return iterator(end1);
        }
    };
}

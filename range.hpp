#pragma once

namespace itertools
{

    template <typename T>
    
    /*
    This class represents a range of objects.
    */
    class range
    {
        protected:
        T start; //The start of the range.
        T end; //The end of the range.

        public:
        
        range(T first, T second) : start(first), end(second)
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
		    return iterator(end);
        }
    };
}

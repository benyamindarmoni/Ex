#pragma once
#include <iostream>

namespace itertools
{
    template <typename T1, typename T2>

    /*
    This class represents a parallel connection of two container-like (like zip)
    */
    class zip 
    {
        private:
        T1 _it1; //Container 1.
        T2 _it2; //Container 2.
        
        public:
        /*
        A copy constructor.
        */
        zip(T1 _start, T2 _end) : _it1(_start), _it2(_end)
        {

        }
        
        template <typename P1, typename P2>

        /*
        This class represents an iterator.
        */
        class iterator
        {
          private:
            P1 data1; //Pointer to the data of the first container.
            P2 data2; //Pointer to the data of the second container.

            public:
            /*
            A copy constructor.
            */
            iterator(P1 ptr1, P2 ptr2) : data1(ptr1), data2(ptr2)
            {

            }

            /*
            For operator *:
            */
            std::pair<decltype(*data1), decltype(*data2)> operator*() const
            {
                return  std::pair<decltype(*data1), decltype(*data2)> (*data1 , *data2);
            }

            /*
            For operator ++:
            */
            iterator<P1, P2>& operator++()
            {
                ++data1; //Advance the first iterator.
                ++data2; //Advance the second iterator.
			    return *this;
            }

            /*
            For operator !=:
            */
		    bool operator!=(iterator<P1,P2> it)
            {
			    return (data1 != it.data1); //Check if one of the iterators reached the end.
            }
        };

        public:

        /*
        This function returns the start of the zip.
        */
        auto begin() const
        {
            return iterator <decltype(_it1.begin()), decltype(_it2.begin())> (_it1.begin(), _it2.begin());
        }

        /*
        This function returns the end of the zip.
        */
        auto end() const
        {
            return iterator <decltype(_it1.end()), decltype(_it2.end())> (_it1.end(), _it2.end());
        }
    };
    
    template <typename T1,typename T2>

    /*
    For operator <<:
    */
    ostream &operator<<(ostream &os, const std::pair<T1,T2> &c) 
    {
        os << c.first << "," << c.second;
        return os;
    }
}

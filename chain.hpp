#pragma once

namespace itertools
{
    template <typename T1, typename T2>

    /*
    This class represents A chain of two containers-like.
    */
    class chain 
    {
        private:
        T1 _it1; //Container 1.
        T2 _it2; //Container 2.
        
        public:
        /*
        A copy constructor.
        */
        chain(T1 _start, T2 _end) : _it1(_start), _it2(_end)
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
            bool whichIt; //Check if the iterator is in the first word or the second.

            public:
            /*
            A copy constructor.
            */
            iterator(P1 ptr1, P2 ptr2) : data1(ptr1), data2(ptr2), whichIt(true)
            {

            }

            /*
            For operator *:
            */
            decltype(*data1) operator*() const
            {
                if (whichIt) 
                {
                    return *data1; //If the iterator is in the first word.
                }
			    return *data2; //If the iterator is in the second word.
            }

            /*
            For operator ++:
            */
            iterator<P1, P2>& operator++()
            {
                if (whichIt) //If the iterator is in the first word.
                {
                    ++data1; //Advance the first iterator.
                    return *this;
                }
                ++data2; //Advance the seccond iterator.
                return *this;
            }

            /*
            For operator !=:
            */
		    bool operator!=(iterator<P1,P2> it)
            {
                if (whichIt && !(data1 != it.data1)) //If the first iterator reached the end of the first word.
                {
                    whichIt = false;
                }
                if (whichIt)
                {
                    return (data1 != it.data1); //If the iterator is in the first word.
                }
                return (data2 != it.data2); //If the iterator is in the second word.
            }
        };

        public:
        /*
        This function returns the start of the chain.
        */
        auto begin() const
        {
            return iterator <decltype(_it1.begin()), decltype(_it2.begin())> (_it1.begin(), _it2.begin());
        }

        /*
        This function returns the end of the chain.
        */
        auto end() const
        {
            return iterator <decltype(_it1.end()), decltype(_it2.end())> (_it1.end(), _it2.end());
        }

    };
}

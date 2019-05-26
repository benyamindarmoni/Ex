#pragma once
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

namespace itertools
{
    template <typename T>

    /*
    This class represents all the subsets of a container-like.
    */
    class powerset
    {
        private:
        T _start; //A container.

        public:
        /*
        A copy constructor.
        */
        powerset(T _sta) : _start(_sta)
        {

        }
        
        template <typename P>
        /*
        This class represents an iterator.
        */
        class iterator
        {
            private:
            P data1; //Pointer to the start data of the container.
            P data2; //Pointer to the end data of the container.
            vector<vector<P>> value; 
            unsigned size;
            unsigned index;


            public:
            /*
            A copy constructor.
            */
            iterator(P ptr1, P ptr2) : data1(ptr1), data2(ptr2), size(0), index(0)
            {
                while (data1 != data2) //Counting how many elements. 
                {
                    size++;
                    ++data1;
                }
                data1 = ptr1;

                size = std::pow(2, size); //Calculating how many groups.
            }

            /*
            For operator *:
            */
           auto operator*()
            {
                vector<P> tempSet = swap(data1, data2);
                value = help(tempSet);

                vector<typename remove_const<typename remove_reference<decltype(*data2)>::type>::type> temp; 

                for (auto i : value[index])
                {
                    temp.push_back(*i);
                }

                return temp;  
            }

            /*
            For operator ++:
            */
            auto operator++()
            {
                ++index;
			    return *this;
            }

            /*
            For operator !=:
            */
		    bool operator!=(iterator<P> it)
            {
			    return (index != size);
            }

            private:

            vector<P> swap(P val1, P val2)
            {
                vector<P> temp;
                P it = val1;

                while (it != val2)
                {
                    temp.push_back(it);
                    ++it;
                }
                
                return temp;
            }

            vector<vector<P>> help(vector<P>& val)
            {
                vector<vector<P>> options;
                vector<P> dataTemp;

                options.push_back(dataTemp);

                for (int i = 0; i < val.size(); i++)
                {
                    vector<vector<P>> temp = options;
                    for (int j = 0; j < temp.size(); j++)
                    {
                        temp[j].push_back(val[i]);
                    }

                    for (int j = 0; j < temp.size(); j++)
                    {
                        options.push_back(temp[j]);
                    }
                }

                return options;
            }
        };

        public:
        
        /*
        This function returns the start of the powerset.
        */
        auto begin() const
        { 
            return iterator<decltype(_start.begin())> (_start.begin(), _start.end());
        }

        /*
        This function returns the end of the powerset.
        */
        auto end() const
        { 
            return iterator<decltype(_start.begin())>(_start.end(), _start.end());
        } 
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, vector<T>& data)
    {
        os << "{";
        auto start = data.begin(); //Starting the iterator.
        if (start != data.end()) //Insert the first data in os.
        {
            os << *start;
            start++;
        }

        while (start != data.end()) //Insert all the rest of the data in os.
        {
            os << "," << *start;
            start++;
        }

        os << "}";
        return os;
    }
}

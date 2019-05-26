#pragma once
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
namespace itertools
{
    template <typename T>
    class powerset
    {
        private:
        T cont; 

        public:
      
        powerset(T x) : cont(x)
        {
        }
        
        template <typename P>
        class iterator
        {
            private:
            P ptr1;
            P ptr2;
            vector<vector<P>> value; 
            unsigned size;
            unsigned index;


            public:
            iterator(P p1, P p2) : ptr1(ptr1), ptr2(ptr2), size(0), index(0)
            {
                while (ptr1 != ptr2) 
                {
                    size++;
                    ++ptr1;
                }
                ptr1 = p1;

                size = std::pow(2, size);
            }

           auto operator*()
            {
                vector<P> temp = swap(ptr1, ptr2);
                value = help(temp);

                vector<typename remove_const<typename remove_reference<decltype(*ptr2)>::type>::type> temp; 

                for (auto i : value[index])
                {
                    temp.push_back(*i);
                }

                return temp;  
            }

            operator ++:
            
            auto operator++()
            {
                ++index;
			    return *this;
            }

      
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
        
        auto begin() const
        { 
            return iterator<decltype(cont.begin())> (cont.begin(), cont.end());
        }
        auto end() const
        { 
            return iterator<decltype(cont.begin())>(cont.end(), cont.end());
        } 
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, vector<T>& data)
    {
        os << "{";
        auto start = data.begin(); 
        if (start != data.end())
        {
            os << *start;
            start++;
        }

        while (start != data.end()) 
        {
            os << "," << *start;
            start++;
        }

        os << "}";
        return os;
    }
}

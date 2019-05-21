#include <set> 
#include <vector>
#include <cmath>
#include <iostream>
#include "zip.hpp"

namespace itertools
{

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &S)
{
    os << "{";

    auto it = S.begin();
    if(it != S.end())
{
        os << *it; 
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}

template <class T>

class _powerset
{

private:
    T _from; 

    template <class E>
  
    class iterator
    {

    public:
        

        E _element_iterator_begin;
        E _element_iterator_end;
        unsigned int index;
        unsigned int num_of_elements;

        //constructor
        iterator(E element_it_begin, E element_it_end) : _element_iterator_begin(element_it_begin),
                                                         _element_iterator_end(element_it_end),
                                                         index(0),
                                                         num_of_elements(0)
        {
            E _element_iterator = _element_iterator_begin;
            while (_element_iterator != _element_iterator_end)
            {
                ++num_of_elements;
                ++_element_iterator;
            }

            num_of_elements = std::pow(2, num_of_elements);
        }

        // operators
        bool operator!=(_powerset::iterator<E> const &other) const
        {
            return ((num_of_elements - index) != (other.num_of_elements - other.index - 1));
        }

        auto operator*() const
        {
            E _element_iterator = _element_iterator_begin;
            std::vector<typename std::remove_const<typename std::remove_reference<decltype(*_element_iterator_begin)>::type>::type> S;
           
            unsigned int i = index;
            while (i != 0 && _element_iterator != _element_iterator_end)
            { 
                unsigned int r = i % 2;
                i = i >> 1; 

                if (r == 1)
                    S.emplace_back(*_element_iterator);

                ++_element_iterator;
            }

            return S;
        }

        _powerset::iterator<E> &operator++()
        {

            ++index;
            return *this;
        }
    };

public:
    _powerset(T from) : _from(from) {}                                                                                                              // constructor
    auto begin() const { return _powerset::iterator<decltype(_from.begin())>(_from.begin(), _from.end()); } 
    auto end() const { return _powerset::iterator<decltype(_from.begin())>(_from.end(), _from.end()); }      
};                                                                                                                                                  // class

template <typename T>

_powerset<T> powerset(T from)
{
    return _powerset<T>(from);
}

}
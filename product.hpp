#include <utility> 

namespace itertools
{


template <class T, class E>

class product
{
   
private:
    T _iteratable_A;    
    E _iteratable_B;    

    template <typename U, typename V>
    class iterator
    {
    public:
        // variables
        U _iterator_A; 
        V _iterator_B; 

        V _iterator_B_start_pos;

        //constructor
        iterator(U iteratable_A, V iteratable_B) : 
            _iterator_A(iteratable_A), 
            _iterator_B(iteratable_B),
            _iterator_B_start_pos(iteratable_B) {}

        // operators
        bool operator!=(product::iterator<U,V> const &other) 
        {            
            if ((_iterator_A != other._iterator_A) && !(_iterator_B != other._iterator_B))
            { 
                _iterator_B = _iterator_B_start_pos;
                ++_iterator_A;
            }

            return (_iterator_A != other._iterator_A);
        }

        std::pair<decltype(*_iterator_A),decltype(*_iterator_B)> operator*() const
        {
            return std::pair< decltype(*_iterator_A),
                              decltype(*_iterator_B)> (*_iterator_A,*_iterator_B);
        }

        product::iterator<U,V> &operator++()
        {
            ++_iterator_B;
            return *this;
        }
    };

public:
    product(T from, E to) : _iteratable_A(from), _iteratable_B(to) {} // constructor

    auto begin() const{ 
        return  product::iterator<decltype(_iteratable_A.begin()),decltype(_iteratable_B.begin())>(_iteratable_A.begin(), _iteratable_B.begin()); }  // iteratable object

    auto end() const {
        return product::iterator<decltype(_iteratable_A.end()),decltype(_iteratable_B.end())>(_iteratable_A.end(), _iteratable_B.end()); }  // iteratable object  
};  

/*template <typename T, typename E>

product<T, E> product(T first, E second)
{
    return product<T, E>(first, second);
}*/

}

namespace itertools
{
template <class T, class E>
class _chain
{
   
private:
    T _iteratable_A;   
    E _iteratable_B;   

   
    template <typename U, typename V>
    class iterator
    {
    public:
       
        U _iterator_A;
        V _iterator_B; 

        bool iterateA;

   
        iterator(U iteratable_A, V iteratable_B) : _iterator_A(iteratable_A), _iterator_B(iteratable_B), iterateA(true) {}

        
        bool operator!=(_chain::iterator<U,V> const &other) 
        {
            if (iterateA && !(_iterator_A != (other._iterator_A))) 
          
                iterateA = false;

            if(iterateA)
                return (_iterator_A != (other._iterator_A));
            else 
                return (_iterator_B != (other._iterator_B));

            
        }

        decltype(*_iterator_A) operator*() const
        {
            if(iterateA)
                return *_iterator_A;
            else
                return *_iterator_B;
        }

        _chain::iterator<U,V> &operator++()
        {
            if(iterateA)
                ++_iterator_A;
            else 
                ++_iterator_B;
            
            return *this;
        }
    };

public:
    _chain(T from, E to) : _iteratable_A(from), _iteratable_B(to) {} // constructor

    auto begin() const{ 
        return  _chain::iterator<decltype(_iteratable_A.begin()),decltype(_iteratable_B.begin())>(_iteratable_A.begin(), _iteratable_B.begin()); }  // iteratable object

    auto end() const {
        return _chain::iterator<decltype(_iteratable_A.end()),decltype(_iteratable_B.end())>(_iteratable_A.end(), _iteratable_B.end()); }  // iteratable object  
};  // class

template <typename T, typename E>

_chain<T, E> chain(T first, E second)
{
    return _chain<T, E>(first, second);
}

}
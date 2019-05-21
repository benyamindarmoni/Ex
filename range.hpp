namespace itertools
{


template <class T>

class _range
{


private:
    T _from;
    T _to;   

    class iterator
    {

    public:
        // variables
        T val;

        //constructor
        iterator(T vall) : val(vall){}

        // operators
        bool operator!=(_range::iterator const &other) const
        { 
            return val != (other.val);
        }

        T operator*() const
        {
            return val;
        }


        _range::iterator &operator++()
        {

            ++val;
            return *this;
        }
    };

public:
    _range(T from, T to) : _from(from), _to(to) {}                     
    _range::iterator begin() const { return _range::iterator(_from); } 
    _range::iterator end() const { return _range::iterator(_to); }      
}; // class



template <typename T>

_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}

}
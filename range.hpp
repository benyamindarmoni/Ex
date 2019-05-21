namespace itertools
{


template <class T>

class range
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
        bool operator!=(range::iterator const &other) const
        { 
            return val != (other.val);
        }

        T operator*() const
        {
            return val;
        }


        range::iterator &operator++()
        {

            ++val;
            return *this;
        }
    };

public:
    range(T from, T to) : _from(from), _to(to) {}                     
    range::iterator begin() const { return range::iterator(_from); } 
    range::iterator end() const { return range::iterator(_to); }      
}; // class


/*
template <typename T>

_range<T> range(T from, T to)
{
    return _range<T>(from, to);
}*/

}

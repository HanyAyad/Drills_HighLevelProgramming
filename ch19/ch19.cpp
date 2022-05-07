#include "std_lib_facilities.h"
template<typename T>
struct S
{
public:

    S& operator=(const T&);

    S(T NewValue) //constructor to initialize with a t
    {
        val = NewValue;
    }

    void set(T NewValue) //Function Template to change val
    {
        val = NewValue;
    }

    S<T> &operator=(S<T> &value);

    T& get();
    const T& get() const;

private:
    T val;
};

template<typename T> //a function template that returns a reference to val
T& S<T>::get()
{
    return val;
}

template<typename T> //const version of get()
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T> //Output layout to print vector elements
ostream& operator<<(ostream& os, vector<T>& v) //ostream is used for output
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T> //Input layout for the inputted vector
istream& operator>>(istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{')
    {
        cout << "error please use '{}'" << endl;
        is.unget();
        return is;
    }

    for (T val; is >> val; )
    {
        v.push_back(val);
        is >> ch;
        if (ch != ',')
        {
            cout << "error please use ','" << endl;
            break;
        }

    }

    return is;
}

template<typename T> void read_val(T& v) //stores the value inputed in v
{
    cin >> v;
}

int main()
{
    S<int> si {5};
    S<char> sc {'A'};
    S<double> sd {3.1};
    S<string> s {"testing"};
    S<vector<int>> svi { vector<int>{1, 2, 3, 4, 5, 6}};

    cout << "S<int> : " << si.get() << '\n'
         << "S<char> : " << sc.get() << '\n'
         << "S<double> : " << sd.get() << '\n'
         << "S<string> : " << s.get() << '\n'
         << "S<vector<int>> : " << svi.get() << '\n';

    sc.set('s');
    cout << "S<char> : " << sc.get() << '\n';

    cout << "Integer: ";
    int ii;
    read_val(ii);
    S<int> si2 {ii};
    cout << "S<int> read: " << si2.get() << '\n' << '\n';

    cout << "Char: ";
    char cc;
    read_val(cc);
    S<char> sc2 {cc};
    cout << "S<char> read: " << sc2.get() << '\n' << '\n';

    cout << "Double: ";
    double dd;
    read_val(dd);
    S<double> sd2 {dd};
    cout << "S<double> read: " << sd2.get() << '\n' << '\n';

    cout << "String: ";
    string ss;
    read_val(ss);
    S<string> s2 {ss};
    cout << "S<string> read: " << s2.get() << '\n' << '\n';

    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> vi2;
    read_val(vi2);
    S<vector<int>> svi2 {vi2};
    cout << "S<vector<int>> read: " << svi2.get() << '\n' << '\n';
}

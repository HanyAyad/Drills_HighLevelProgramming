#include "std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a) //Function To Print array of 10 ints
{
    for(int i = 0; i < 10; i++)
    {
        os << a[i] << ' ';
    }
    return os;
}


ostream& print_array(ostream& os, int* a, int n)//Function To Print array of n ints
{
    for(int i = 0; i < n; i++)
    {
        os << a[i] << ' ';
    }
    return os;
}

ostream& print_vector10(ostream& os,vector<int>& v) //Function to print vector
{
    for(int i = 0; i < 10; i++)
    {
        os << v[i] << ' ';
    }
    return os;
}

int main()
{
    int num= 7;
    int* p1= &num;
    cout<<"p1 address:   "<<p1<<"  p1 number pointing to it: "<<*p1<<endl;


    int* p2= new int[7];
    for(int i=0; i<=7;i++)
    {
        p2[i]=pow(2,i);
    }
    cout<<"p2 address:   "<<p2<<endl;
    cout<<"p2 values:   ";
    for (int i= 0; i< 7; i++)
        cout << p2[i] << " ";
    cout<<endl;

    int*p3=p2;
    p2=p1;
    p2=p3;

    cout<<"p1 address:   "<<p1<<"  p1 value: "<<*p1<<endl;
    cout<<"p2 address:   "<<p2<<"  p2 value: "<<*p2<<endl;


    delete[]p1;
    delete[]p2;
    delete[]p3;

    p1= new int[10];
    for(int i=0;i<10;i++)
    {
        p1[i]=pow(2,i);
    }

    p2= new int[10];
    for(int i=0;i<10;i++)
    {
       p2[i]=p1[i];
    }
    cout<< "array: ";
    print_array10(cout,p2);
    cout<<endl;
    delete[]p1;
    delete[]p2;


    vector<int> p11{1,2,3,4,5,6,7,8,9,10};
    vector<int> p22= p11;
    cout<<"vector: ";
    print_vector10(cout,p22);
}

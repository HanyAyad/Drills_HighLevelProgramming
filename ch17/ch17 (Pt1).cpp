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
    int size = 10;
    int* arr10 = new int[size]; //Allocating array of ten ints on the free store using new

    for(int i = 0; i < size; i++) //creating a for loop to asign values to arr10
    {
        arr10[i] = i;
    }
    cout << "array10:" << ' ';
    print_array10(cout, arr10); //calling function print_array10
    cout<<endl;

    delete[] arr10; //deallocate the array

    for(int i = 0; i < size; i++) //loop to assign values 100,101,... to arr10
    {
        arr10[i] = i + 100;
    }
    cout << "array100:" << ' ';
    print_array10(cout, arr10); //calling function print_array10
    cout<<endl;

    int* arr11 = new int[11]; //allocating new array of 11 ints
    for(int i = 0; i < 11; i++) //assigning values 100,101,... to arr11
    {
        arr11[i] = i+100;
    }
    cout << "array11:" << ' ';
    print_array(cout, arr11,11);//calling function print_array to print 11 elements
    cout<<endl;

    int* arr20 = new int[20]; //allocating new array of 20 ints
    for(int i = 0; i < 20; i++) //assigning values 100,101,... to arr20
    {
        arr20[i] = i+100;
    }
    cout << "array20:" << ' ';
    print_array(cout, arr20,20); //calling function print_array to print 20 elements
    cout<<endl;

    int y = 0;
    vector<int> vec10(10); //allocating new vector with 10 ints
    for(int& v:vec10) //assigning values for each int 'v' in 'vec10'
    {
        v = y;
        y++;
    }
    cout << "vector10:" << ' ';
    print_vector10 (cout, vec10); //calling function print_vector10 to print the vector
    cout<<endl;
    return 0;
}

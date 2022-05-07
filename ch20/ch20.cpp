#include "std_lib_facilities.h"


    template<typename C> //Defining new template
void print_contents(const C& c) //creating function to print content of list
{
    cout <<"Content: " ;
    for (auto& a : c) // For each element 'a' inside the list 'c'
    cout << a << ' '; //Print element 'a'
    cout << '\n';
}
    template<typename C> //Defining new template
void print_contents(const C& c, int n) //creating function to print content of list+n
{
    cout<<"Contents: ";
    for (auto& a : c) // For each element 'a' inside the list 'c'
        cout << a+n << ' '; //Print element 'a+1'
        cout << '\n';
}
template<typename Iter1, typename Iter2>
    // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) //Function to copy vector to its copy
{
    for (Iter1 p = f1; p != e1; ++p) // set p at beginning of vec, as long as != the end, ++p
        *f2++ = *p; //assign *p to the beginning of vec 2 and move to the next element with each loop
    return f2; //return the vector copy
}

int main(){
    array<int,10> arr={0,1,2,3,4,5,6,7,8,9}; // Defining an array
    vector <int> vec = {0,1,2,3,4,5,6,7,8,9};// Defining a vector
    list <int> li= {0,1,2,3,4,5,6,7,8,9};// Defining a ist

    array<int,10> arr_copy=arr;// Defining an array copy
    vector <int> vec_copy= vec;// Defining an a vector copy
    list <int> li_copy= li;// Defining a list copy

    print_contents(li); //calling function print content
    print_contents(li,2);//calling function print content+2
    print_contents(li,3);//calling function print content+3
    print_contents(li,5);//calling function print content+5
    my_copy(arr.begin(),arr.end(),vec_copy.begin()); //copying the array into the vector
    my_copy(li.begin(),li.end(),arr_copy.begin()); // copying the list into the array
    print_contents(vec_copy);// Print the contents of the vec copy
    print_contents(vec_copy);// Print the contents of the arr copy

    vector<int>::iterator vit; //we intiate an iterator vit
    vit = find(vec_copy.begin(), vec_copy.end(), 3); //we use find to search from vec beginning to vec end for 3
    if (vit != vec_copy.end()) //as long as the iterator doesn't reach the end which is null
        cout << "Found at: " << distance(vec_copy.begin(), vit) << '\n'; //print the position of 3
    else
        cout << "Not found..\n";

    list<int>::iterator lit;
    lit = find(li_copy.begin(), li_copy.end(), 27);
    if (lit != li_copy.end())
        cout << "Found at: " << distance(li_copy.begin(), lit) << '\n';
    else
        cout << "Not found..\n";

}

#include "std_lib_facilities.h"


int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int ai[], int n)
{

    int la[10] = { };
    for (int i = 0; i < n; i++)
        la[i] = ai[i];

    cout << "Array copy: ";
    for (auto& a : la)
        cout << a << ' ';
    cout << endl;

    int* p = new int[10];
    for (int i = 0; i < n; i++)
        p[i] = ai[i];

    cout << "Free-store Array: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;

    delete[] p;
}

int arr_fac(int n) {
     return n > 1 ? n * arr_fac(n - 1) : 1;
     }

int main()
try {

    cout << "Binary array:"<<endl;
    f(ga, 10);

    int aa[10] = {};
    for (int i = 0; i < 10; i++)
        aa[i] = arr_fac(i + 1);

    cout << "Factorial array: "<<endl;
    f(aa, 10);
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown exception\n";
    return 2;
}

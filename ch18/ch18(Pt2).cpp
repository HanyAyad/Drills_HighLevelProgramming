#include "std_lib_facilities.h"

vector <int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};



void f(vector<int> vec)
{

    vector<int> lv(vec.size());

    for (int i = 0; i < 10; i++)
        lv[i] = vec[i];

    cout << "Local Vector1: ";
    for (auto& a : lv)
        cout << a << ' ';
    cout << endl;

    vector<int> lv2 =vec;

    cout << "Local Vector2: ";
        for (auto& a : lv)
        cout << a << ' ';
    cout << endl;
}

int vec_fac(int n) {
     return n > 1 ? n * vec_fac(n - 1) : 1;
     }

int main()
try {
    cout << "Binary Vector: "<<endl;
        f(gv);

    vector<int> vv (gv.size());
    for (int i = 0; i < 10; i++)
         vv[i] = vec_fac(i+1);

    cout << "Factorial Vector: "<<endl;
    f(vv);

}
catch (exception& e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown exception\n";
    return 2;
}

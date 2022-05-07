#include "std_lib_facilities.h"

void swap_v(int a, int b) //No Swap Because Pass By Value (only copy of a and b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) //Swap Because Pass By Reference (Changes the value by pointing to its address)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& a, const int& b) /*No Swap Because Constant Variables
                                          (Without & would run but still no swap)*/
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int mani(){

int x = 7;
int y =9;
swap_v(x,y); // replace ? by v, r, or cr
swap_r(7,9);
const int cx = 7;
const int cy = 9;
swap_r(cx,cy);
swap_cr(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_v(dx,dy);
swap_r(7.7,9.9);

cout << "x: " << x << '\n'
         << "y: " << y << '\n'
         << "cx: " << cx << '\n'
         << "cy: " << cy << '\n'
         << "dx: " << dx << '\n'
         << "dy: " << dy << '\n';

}

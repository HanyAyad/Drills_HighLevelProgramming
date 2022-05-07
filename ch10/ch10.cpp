#include "std_lib_facilities.h"

struct Point { //Defining Data Type point
    int x;
    int y;
};

istream& operator>>(istream& is, Point& p) //Istream to input point
{
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2; // the next character ','
    char ch3; // the last character ')'
    int xx;
    int yy;
    is >> xx >> ch2 >> yy >> ch3;
    if (!is || ch2 != ',' ||ch3 != ')') {
        if (is.eof()) return is;  //EOF indicates end of input
        error("bad point");
    }
    p.x = xx;  //assigning inputted values to coordinates of p of data type Point
    p.y = yy;
    return is;
}

ostream& operator<<(ostream& os, Point& p) //Ostream to output the final layout of the point
{
    return os << '(' << p.x << ',' << p.y << ')';
}


void fill_from_file(vector<Point>& points, string& name) // Function to Read points back in from file
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

int main()

//Allocating vector to store the points
try { //testing for errors while executing
    cout << "Please enter seven sets of x, y points:\n";
    vector<Point> original_points;
    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

//printing original_post data
    for (Point p : original_points)
        cout << p;
    cout << '\n';

    //creating a file
    string fname = "mydata.txt";
    ofstream ost { fname };
    if (!ost) error("could not open file ", fname);
    for (Point p : original_points)
        ost << p;
    ost.close();

    // Refilling the vector from the data in file
    vector<Point> processed_points;
    fill_from_file(processed_points, fname);

    for (Point p : processed_points)
        cout << p;
    cout << '\n';

    //error message if size is different
    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n'; //for any error, a message is shown as an exception and the code still runs
    return 1;
}
catch (...) {
    cerr << "Something terrible has happened!\n";
    return 2;
}

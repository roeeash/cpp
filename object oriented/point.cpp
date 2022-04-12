#include "Point.h"

using namespace std;

int main()
{
    complex a(1, 2);
    complex b(3, 4);
    Point p = Point(a, b);
    cout << "" + p.to_string() << endl;
}
#include "complex.h"

using namespace std;
class Point
{
private:
    complex x, y;
    // default constructor
public:
    Point(complex x, complex y)
    {
        this.x = x;
        this.y = y;
    }
    // point as 4 ints
    Point(int a, int b, int c, int d)
    {
        this.x = complex(a, b);
        this.y = complex(c, d);
    }
    Point()
    {
    }
    Point operator+(Point a, Point b)
    {
        return Point(a.x + b.x, a.y + b.y);
    }
};
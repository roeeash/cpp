#ifndef POINT_H
#define POINT_H

#include "complex.h"
using namespace std;
class Point
{

public:
    Point();
    Point(complex x, complex y);
    // point as 4 ints
    Point(int a, int b, int c, int d);
    Point operator+(Point other);
    Point operator-(Point other);
    string to_string();

private:
    complex x, y;
};



#endif
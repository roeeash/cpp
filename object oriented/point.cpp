#include "Point.h"
#include <cstring>

using namespace std;
class Point
{
    Point::Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point::Point(complex x, complex y)
    {
        this->x = x;
        this->y = y;
    }
    // point as 4 ints
    Point::Point(int a, int b, int c, int d)
    {
        this->x = complex(a, b);
        this->y = complex(c, d);
    }

    Point::Point operator+(Point other)
    {
        return Point(x + other.x, y + other.y);
    }
    Point::Point operator-(Point other)
    {
        return Point(x - other.x, y - other.y);
    }
    Point::string to_string()
    {
        string str = "";
        string x_value = "(";
        string y_value = "(";

        x_value += std::to_string(x.get_r());
        x_value += ",";
        x_value += std::to_string(x.get_i());
        x_value += ")";

        y_value += std::to_string(y.get_r());
        y_value += ",";
        y_value += std::to_string(y.get_i());
        y_value += ")";

        str = x_value + " , " + y_value;

        return str;
    }
};
#include <iostream>
#include <string>
#include "complex.h"
#include "Point.h"

using namespace std;

class colorPoint : public Point
{
private:
    string color;

public:
    colorPoint(int x, int y, int z, int w, string color) : Point(x, y, z, w)
    {
        this->color = color;
    }
    string to_string()
    {
        return Point::to_string() + " , color : " + this->color;
    }
};

int main()
{
    colorPoint p = colorPoint(1, 2, 3, 4, "red");
    cout << "" + p.to_string() << endl;
    return 0;
}
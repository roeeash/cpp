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

        str = x_value + " , " + y_value + " " + color;

        return str;
    }
};

int main()
{
    colorPoint p = colorPoint(1, 2, 3, 4, "red");
    cout << "" + p.to_string() << endl;
    return 0;
}
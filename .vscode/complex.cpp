#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

// class complex
class complex
{
private:
    float r, i;

public:
    // constructor
    complex(float r, float i)
    {
        this->r = r;
        this->i = i;
    }

    // empty constructor
    complex() {}
    void print_complex()
    {
        cout << "The real part is: " << r << endl;
        cout << "The imaginary part is: " << i << endl;
    }
    // addition
    complex operator+(complex c)
    {
        return complex(r + c.r, i + c.i);
    }
    // subtraction
    complex operator-(complex c)
    {
        return complex(r - c.r, i - c.i);
    }
    float operator|(int)
    {
        return sqrt(r * r + i * i);
    }
};

int main()
{
    complex a(1, 2);
    complex b(3, 4);
    a.print_complex();
    float n = a | 2;
    cout << "a's norm is : " << n << endl;
    return 0;
}
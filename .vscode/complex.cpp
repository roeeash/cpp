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
    // find the n-th norm
    float operator|(int p)
    {
        float real = pow(r, p);
        float im = pow(i, p);
        return pow((real + im), 1.0 / p);
    }
    complex operator*(complex c)
    {
        //(a+bi)*(x+yi) = (a*x-by+(b*x+a*y)*i)
        return complex((r * c.r - i * c.i), (i * c.r + r * c.i));
    }
};

int main()
{
    complex a(1, 2);
    complex b(3, 4);
    a.print_complex();
    float n = a | 3;
    cout << "a's norm is : " << n << endl;
    complex c = a * b;
    c.print_complex();
    return 0;
}
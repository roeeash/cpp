#ifndef COMPLEX_H
#define COMPLEX_H

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
    // find the p-th norm of the number
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

#endif
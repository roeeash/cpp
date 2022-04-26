#ifndef COMPLEX_H
#define COMPLEX_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
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
    string to_string()
    {
        string str = "";
        string real = "The real part is: ";
        string im = "The imaginary part is: ";

        real += std::to_string(r);
        real += "\n";
        im += std::to_string(i);
        str = real + im;

        return str;
    }
    float get_r()
    {
        return this->r;
    }
    float get_i()
    {
        return this->i;
    }
};

#endif
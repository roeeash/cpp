#include "complex.h"

using namespace std;

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
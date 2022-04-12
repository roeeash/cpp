#include "complex.h"

using namespace std;

int main()
{
    complex a(1, 2);
    complex b(3, 4);
    // a.print_complex();
    //  supposed to be the same as a.print_complex()
    cout << "" + a.to_string() << endl;
    float n = a | 3;
    cout << "a's norm is : " << n << endl;
    complex c = a * b;
    c.print_complex();
    return 0;
}
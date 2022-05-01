#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int smallestWithSame(int num)
{
    int digits = 0;
    while (num)
    {
        digits++;
        num /= 10;
    }

    if (digits)
    {
        return pow(10, digits - 1);
    }
    return 0;
}

string findMaxInteger(int num, int &digit)
{
    string s = to_string(num);
    string compString;
    int currDigit;
    int flag = 0;

    for (int i = 0; i < s.size(); i++)
    {
        currDigit = (int)(s[i] - '0');

        if (currDigit < digit && !flag)
        {
            cout << "currDigit = " << currDigit << endl;
            cout << "digit = " << digit << endl;
            compString += to_string(digit);
            flag = 1;
        }
        compString += s[i];
    }
    return compString;
}

int main()
{
    int num, digit;
    cin >> num;
    cout << smallestWithSame(num) << endl;
    return 0;
}
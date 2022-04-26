#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// macros
// infinity
#define INF 1000000
// for each loop
#define foreach(v, i) for (int i = 0; i < v.size(); i++)
// io
#define io(v) cin >> v
// to_string
#define toStr(x) #x
// FUNCTION - if b op a then a = b
#define FUNCTION(name, sign) \
    void name(int &a, int b) \
    {                        \
        if (b sign a)        \
            a = b;           \
    }
// create minimum and maximum functions using macro
FUNCTION(maximum, >)
FUNCTION(minimum, <)

int main()
{

    int length;
    int value;

    // input into length
    cin >> length;
    vector<int> v(length);

    foreach (v, i)
    {
        io(v)[i];
    }
    int min = INF;
    int max = -INF;

    foreach (v, i)
    {
        maximum(max, v[i]);
        minimum(min, v[i]);
    }

    // search for min
    auto it = find(v.begin(), v.end(), min);
    if (it != v.end())
    {
        cout << "minimum at " << distance(v.begin(), it) << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    // search for max
    it = find(v.begin(), v.end(), max);
    if (it != v.end())
    {
        cout << "maximum at " << distance(v.begin(), it) << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void moveZeroes(vector<int> &vec)
{
    int n = vec.size();
    int counter = 0;

    for (int i = n - 1; i - counter >= 0; i--)
    {

        // base case: last index
        if (vec[i - counter] == 0)
            counter++;

        if (vec[i - counter] == 0 && vec[i] == 0)
            counter++;

        cout << "i = " << i << " vec [i] = " << vec[i] << " vec [i - counter] = " << vec[i - counter]
             << " counter = " << counter << endl;
        if (counter && i != 0)
        {

            swap(vec[i], vec[i - counter]);
        }
    }
}

int main()
{
    // vector<int> v2 = {1, 0, 2};
    vector<int> v = {16, 0, 0, 7, 12, 0, 0, 3, 0, 59, -1, 0, 2};
    moveZeroes(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
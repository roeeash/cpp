#include <iostream>
#include <deque>

using namespace std;
// finds all max's of k contingous sub arrays
void printKMax(int arr[], int n, int k)
{
    // d saves the indices and returns the index of the k max
    deque<int> d;

    for (int i = 0; i < n; i++)
    {
        if (d.empty())
        {
            d.push_back(i);
        }
        // no more than k elements
        if (d.front() <= (i - k))
        {
            d.pop_front();
        }
        while (!d.empty() && arr[i] >= arr[d.back()])
        {
            d.pop_back();
        }

        d.push_front(i);

        // print the k max
        if (i >= (k - 1))
        {
            cout << arr[d.front()] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool subsetSumIterative(vector<int> const &A, int k)
{
    int n = A.size();

    bool tab[n + 1][k + 1];

    // base case: zero items but sum is non-zero
    for (int j = 0; j < k + 1; j++)
    {
        tab[0][j] = false;
    }
    // base case: sum is zero
    for (int i = 0; i < n + 1; i++)
    {
        tab[i][0] = true;
    }

    // non trivial cases
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            // case: A[i-1] > j - don't include it in the process
            if (A[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                // include/exclude
                tab[i][j] = tab[i - 1][j] || tab[i - 1][j - A[i - 1]];
            }
        }
    }
    return tab[n][k];
}

// Returns true if there exists a subsequence of `A[0…n]` with the given sum
bool subsetSum(vector<int> const &A, int n, int k, map<string, bool> &lookup)
{
    // return true if the sum becomes 0 (subset found)
    if (k == 0)
    {
        return true;
    }

    // base case: no items left, or sum becomes negative
    if (n < 0 || k < 0)
    {
        return false;
    }

    string key = to_string(n) + "|" + to_string(k);

    if (lookup.find(key) == lookup.end())
    {

        bool include = subsetSum(A, n - 1, k - A[n], lookup);

        bool exclude = subsetSum(A, n - 1, k, lookup);

        lookup[key] = include || exclude;
    }
    return lookup[key];
}

// Subset Sum Problem
int main()
{
    // Input: a set of items and a sum
    vector<int> A = {7, 3, 2, 5, 8};
    int k = 14;

    // total number of items
    int n = A.size();

    map<string, bool> mp;

    if (subsetSum(A, n - 1, k, mp))
    {
        cout << "Subsequence with the given sum exists";
    }
    else
    {
        cout << "Subsequence with the given sum does not exist";
    }
    cout << endl;
    if (subsetSumIterative(A, k))
    {
        cout << "Subsequence with the given sum exists (iterative search)";
    }
    else
    {
        cout << "Subsequence with the given sum does not exist (iterative search)";
    }
    cout << endl;

    return 0;
}
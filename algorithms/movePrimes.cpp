#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void swap(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}

void printVector(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;
    int num;
    vector<int> nums;
    int curr = 0;
    int lastToSwap;
    int cap;
    int prevSwap = -1;
    int minPenalty = 0;
    int optionOne = 0, optionTwo = 0;

    cin >> n;

    lastToSwap = n - 1;

    cap = lastToSwap;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    while (cap--)
    {

        while (isPrime(nums[cap]) == curr)
        {

            curr = !curr;
            swap(nums[cap], nums[lastToSwap]);
            lastToSwap--;
        }

        printVector(nums);
    }

    for (int i = 0; i <= lastToSwap; i++)
    {
        if (i != lastToSwap)
        {
            optionOne += nums[i];
            optionTwo += nums[i];
        }
        else
        {
            optionOne += nums[i];
            optionTwo += (lastToSwap < n - 1 && isPrime(nums[i + 1]) == isPrime(nums[i]))
                             ? nums[i + 1]
                             : nums[i];
        }
    }

    minPenalty = min(optionOne, optionTwo);

    cout << "minPenalty = " << minPenalty << endl;

    return 0;
}

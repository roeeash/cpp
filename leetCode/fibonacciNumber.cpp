class Solution
{
public:
    map<int, int> lookup;

    int fibMemo(int n)
    {
        int res;
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
        {
            return 1;
        }
        if (lookup.find(n) != lookup.end())
        {
            return lookup[n];
        }
        else
        {
            res = fibMemo(n - 1) + fibMemo(n - 2);
            lookup[n] = res;
            return res;
        }
    }
    int fib(int n)
    {
        return fibMemo(n);
    }
};
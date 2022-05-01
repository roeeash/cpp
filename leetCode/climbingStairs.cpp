class Solution
{
public:
    map<int, int> lookup;

    int memo(int n)
    {
        int res;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (lookup.find(n) != lookup.end())
        {
            return lookup[n];
        }
        else
        {
            res = memo(n - 1) + memo(n - 2);
            lookup[n] = res;
            return res;
        }
    }

    int climbStairs(int n)
    {
        return memo(n);
    }
};
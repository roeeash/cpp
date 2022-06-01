#include <stdio.h>

int climbStairs(int n)
{
    int *res = (int *)malloc(n * sizeof(int));
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    res[0] = 1;
    res[1] = 2;

    for (int i = 2; i < n; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }

    return res[n - 1];
}
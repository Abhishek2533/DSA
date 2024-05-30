#include <bits/stdc++.h>
long long int sumOrProduct(long long int n, long long int q)
{
    long long int sum = 0, prod = 1;

    if (q == 1)
    {

        for (int i = 1; i <= n; i++)
        {

            sum = sum + i;
        }

        return sum;
    }

    else if (q == 2)
    {

        for (int i = 1; i <= n; i++)
        {

            prod = (prod * i) % 1000000007;
        }

        return prod;
    }
}
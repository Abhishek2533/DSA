#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    int res = 1;

    while (n > 0)
    {
        // odd
        if (n & 1)
        {
            // maybe out of range of typecast to long long --> (1LL)
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        // divide by 2 using bit as it is fast/easy
        n = n >> 1;
    }
    return res;
}
#include <bits/stdc++.h>

bool isPossible(vector<int> time, int n, int m, long long mid)
{
    long long timeCount = 0;
    long long days = 1;
    for (long long i = 0; i < m; i++)
    {
        if (timeCount + time[i] <= mid)
        {
            timeCount += time[i];
        }
        else
        {
            days++;
            if (days > n || time[i] > mid)
            {
                return false;
            }
            timeCount = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long sum = 0;
    long long ans = -1;
    for (long long i = 0; i < m; i++)
    {
        sum += time[i];
    }

    long long start = 0;
    long long end = sum;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossible(time, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
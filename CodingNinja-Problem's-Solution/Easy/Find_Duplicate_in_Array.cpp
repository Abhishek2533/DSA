#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int i = 1;
    while (i < n)
    {
        if (arr[i] == arr[i - 1])
            return arr[i];
        i++;
    }
}

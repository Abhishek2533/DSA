#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    int i = 0;
    int j = n - 1;
    int c = 0;
    while (c <= j)
    {
        while (c <= j && arr[c] == 0)
        {
            swap(arr[c], arr[i]);
            c++;
            i++;
        }
        while (c <= j && arr[c] == 2)
        {
            swap(arr[c], arr[j]);
            j--;
        }
        while (c <= j && arr[c] == 1)
        {
            c++;
        }
    }
    return;
}
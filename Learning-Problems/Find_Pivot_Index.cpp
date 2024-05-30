#include <iostream>
using namespace std;

int findPivotIndex(int arr[], int n)
{
    int s = 0, e = n - 1;
    int left = 0, right = 0;
    int mid = s + (e - s) / 2;
    while (left != right)
    {
        for (int i = 0; i < mid; i++)
        {
            left = left + arr[i];
        }

        for (int i = mid + 1; i < n; i++)
        {
            right = right + arr[i];
        }

        if (left < right)
        {
            mid = mid + 1;
        }
        else if (left > right)
        {
            mid = mid - 1;
        }
        else
        {
            mid = mid;
        }
    }
    return mid;
}

int main()
{
    int arr[6] = {1, 7, 3, 6, 5, 6};

    int index = findPivotIndex(arr, 6);

    cout << "Pivot index is " << index;
}
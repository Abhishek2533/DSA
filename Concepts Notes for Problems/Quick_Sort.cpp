#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;

    // placing pivot at right position
    swap(arr[s], arr[pivotIndex]);

    // sorting left and right part
    int i = s, j = e;
    while (i<pivotIndex && j> pivotIndex)
    {
        while (arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }

        if (i<pivotIndex && j> pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return ;
    }

    // partition
    int p = partition(arr, s , e);

    // sorting left part
    quickSort(arr, s, p-1);

    // sorting right part
    quickSort(arr, p+1, e);
}

int main()
{
    int arr[13] = {2, 4, 1, 5, 9, 4, 6, 7, 1, 2, 3, 3, 3};
    int n = 13;

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
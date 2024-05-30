#include <iostream>
using namespace std;

void sort012(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] == 0)
        {
            left++;
        }
        while (arr[right] >= 1)
        {
            right--;
        }
        while (arr[left] > 0 && arr[right] == 0)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    int i = 0, j = n - 1;
    while (i < j)
    {
        while (arr[i] <= 1)
        {
            i++;
        }
        while (arr[j] == 2)
        {
            j--;
        }
        while (arr[i] == 2 && arr[j] == 1)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};

    sort012(arr, 9);
    printArray(arr, 9);
}
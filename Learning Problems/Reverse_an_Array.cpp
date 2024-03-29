#include <iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);     
        //  swap is a inbuld function which can be breakdown into:
        //  swap(arr[0],arr[1]) -> temp = arr[1] 
        //                        arr[1] = arr[0]
        //                        arr[0] = temp
        start++;
        end--;
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
    int arr[6] = {1, 3, 4, 6, -2, 5};
    int brr[5] = {3, -4, 9, 6, 5};

    reverse(arr, 6);
    reverse(brr, 5);

    printArray(arr, 6);
    printArray(brr, 6);
}
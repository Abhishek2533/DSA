#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i+1<n)
        {
            swap(arr[i], arr[i + 1]);
        }
        
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int even[6] = {0, 1, 2, 3, 4, 5};
    int odd[7] = {0, 1, 2, 3, 4, 5, 11};

    swapAlternate(even, 6);
    swapAlternate(odd, 7);

    printArray(even, 6);
    cout << endl;
    printArray(odd, 7);
}
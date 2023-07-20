#include <iostream>
using namespace std;

bool search(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int size;
    cin >> size;

    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value to be searched: ";
    int value;
    cin >> value;

    int foundValue = search(arr, size, value);

    if (foundValue)
    {
        cout << "Value is found" << endl;
    }
    else
    {
        cout << "Value is not found" << endl;
    }
}
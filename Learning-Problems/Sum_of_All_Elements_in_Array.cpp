#include<iostream>
using namespace std;

int sumOfArr(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
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

    cout << "Total Sum of all Elements in Array is "<< sumOfArr(arr, size) << endl;
    
}
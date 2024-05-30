#include<iostream>
using namespace std;

void printSum(int arr[][3], int row, int col)
{
    cout << "Printing the sum of array row-wise: ";
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum = sum + arr[row][col];
        }
        cout << sum << " ";
    }
    
}

int main()
{
    // created array
    int arr[3][3];

    // taking input row-wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // calling sum function
    printSum(arr, 3, 3);
    
}
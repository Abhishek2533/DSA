#include<iostream>
using namespace std;


bool isPresent(int arr[][4], int target, int row, int col)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
            
        }
    }
    return 0;
}

int main()
{
    // create 2d array
    int arr1[3][4];
    int arr2[3][4];

    // taking input row wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr1[i][j];
        }
    }
    
    // taking input col wise
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr2[j][i];
        }
    }


    

    // print 2d array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }



    // searching an element
    cout << "Enter the element to be searched: ";
    int target;
    cin >> target;

    if (isPresent(arr1, target, 3, 4))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}
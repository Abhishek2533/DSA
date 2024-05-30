#include <iostream>
using namespace std;

int main()
{
    int row;
    cin >> row;

    int col;
    cin >> col;



    // creating 2D array dynamic

    int **arr = new int *[row]; // this creates an  array of size n
    // creating coloumns for each row using the following way:
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];  // this will create col in each row which makes it 2D aray
    }

    // creation done




    // taking inputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }



    // taking output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }



    // releasing the memory
    for (int i = 0; i < row; i++)
    {
        delete [] arr[i];       // this will delete col memory
    }

    delete [] arr;      // this will delete row memory

    return 0;
}
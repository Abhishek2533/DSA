// Hollow Rectangle pattern

// ****
// *  *
// *  *
// *  *
// ****


#include<iostream>
using namespace std;

int main()
{
    int row,coloumn;
    cin >> row >> coloumn;
    for (int i=1;i<=row;i++)
    {
        for (int j = 1;j <= coloumn;j++)
        {
            if (i==1 || i==row || j ==1 || j==coloumn)
            {
                cout << "*";
            }
            // else if (j ==1 || j==coloumn)
            // {
            //     cout << "*";
            // }
            else 
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
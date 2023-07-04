// Rectangle pattern

// ****
// ****
// ****
// ****
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
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
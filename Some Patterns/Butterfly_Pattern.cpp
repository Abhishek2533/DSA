// Butterfly Pattern

//      *             *
//      * *         * *
//      * * *     * * *
//      * * * * * * * *
//      * * * * * * * *
//      * * *     * * *
//      * *         * *
//      *             *

//  n=4; 8 rown & 8 coloumns i.e., 2*n


#include<iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    //Upper half of 4 rows & 8 coloumns
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
            
        }
        int space = 2*n - 2*i;
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
            
        }
        cout << endl;
    }

    // Lower half which is mirror of upper
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
            
        }
        int space = 2*n - 2*i;
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
            
        }
        cout << endl;
    }   
    
}
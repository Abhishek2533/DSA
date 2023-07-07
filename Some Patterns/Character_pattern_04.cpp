// Character/Alphabetic pattern

// A B C D E
// B C D E F
// C D E F G
// D E F G H
// E F G H I

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            int value = (row + col - 1);
            char val = 'A' - 1 + value;
            cout << val << " ";
        }
        cout << endl;
    }
}
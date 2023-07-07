// Character/Alphabetic pattern

// E
// D E
// C D E
// B C D E
// A B C D E

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        char val = 'A' + n - row;
        for (int col = 1; col <= row; col++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }
}
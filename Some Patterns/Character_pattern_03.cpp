// Character/Alphabetic pattern

// A B C D E
// F G H I J
// K L M N O
// P Q R S T
// U V W X Y

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char val = 'A';

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            // char ch = 'A' + col - 1;
            cout << val << " ";
            val = val + 1;
        }
        cout << endl;
    }
}
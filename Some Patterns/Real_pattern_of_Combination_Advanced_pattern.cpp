// Do Yourself for geting better in Patterns
// this is enough for mind exercise

// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

#include <iostream>
using namespace std;

int main()
{

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }

        while (i >= 2)
        {
            for (int a = 1; a < i; a++)
            {
                cout << "*" << " ";
                cout << "*" << " ";
            }
            break;
        }

        for (int b = n - i + 1; b >= 1; b--)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}
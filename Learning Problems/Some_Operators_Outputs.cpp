#include <iostream>
using namespace std;

int main()
{

    // 1.

    int a, b = 1;
    a = 10;
    if (++a)
    {
        cout << b;
    }
    else
    {
        cout << ++b;
    }

    // 2.

    int c = 1;
    int d = 2;
    if (c-- > 0 && ++d > 2)
    {
        cout << "Stage 1 - Inside if";
    }
    else
    {
        cout << "Stage 2 - Inside else";
    }
    cout << endl;
    cout << c << " " << d << endl;

    // 3.

    int e = 1;
    int f = 2;
    if (e-- > 0 || ++f > 2)
    {
        cout << "Stage 1 - Inside if";
    }
    else
    {
        cout << "Stage 2 - Inside else";
    }
    cout << endl;
    cout << e << " " << f << endl;

    // 4.

    int number = 3;
    cout << (25 * (++number)) << endl;

    // 5.

    int p = 1;
    int q = p++;
    int r = ++p;

    cout << q;
    cout << endl;
    cout << r;
}
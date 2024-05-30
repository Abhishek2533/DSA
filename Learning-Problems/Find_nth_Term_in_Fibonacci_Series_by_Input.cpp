/*

Suppose a Fibonacci Series have nth term and user input a number which lies in series
so find the pervious term of that input
e.g. ->
    series = 0, 1, 2, 3, 5, 8, 13, 21, ...
    inp = 5, then outp = 3

*/

#include <iostream>
using namespace std;

int prevTerm(int n)
{
    int a = 0, b = 1, c = 0;
    while(c < n)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    cout << prevTerm(n) << endl;
    return 0;
}
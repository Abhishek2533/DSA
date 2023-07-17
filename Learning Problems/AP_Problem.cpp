/*

Suppose an AP is given as (3*n + 7)
if input is 3 then output is 16

*/

#include <iostream>
using namespace std;

int ap(int n)
{
    int func = (3 * n) + 7;
    return func;
}

int main()
{
    int n;
    cin >> n;

    int ans = ap(n);

    cout << ans;
}
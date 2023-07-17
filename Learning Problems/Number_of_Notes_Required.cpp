/*

Suppose we have ₹1330, now we have find the number of required to complete this amount. The value of given notes are : ₹100, ₹50, ₹20, ₹10, ₹1

The amount is taken from the user
using switch statement

*/

#include <iostream>
using namespace std;

int main()
{
    int amount;
    cin >> amount;

    int n100 = 0,amount1;

    switch (amount)
    {
    case 1:
        n100 = amount / 100;
        amount1 = amount - (n100 * 100);
        cout << n100 << endl;
        break;
    }
}
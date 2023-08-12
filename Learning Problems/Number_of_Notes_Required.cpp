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
    cout << "Enter Your Amount: ";
    cin >> amount;

    int n100 = 0, n50 = 0, n20 = 0, n10 = 0, n1 = 0;

    while (amount > 0)
    {
        switch (amount / 100)
        {
        case 0:
            switch (amount / 50)
            {
            case 0:
                switch (amount / 20)
                {
                case 0:
                    switch (amount / 10)
                    {
                    case 0:
                        n1 = amount;
                        amount = 0;
                        break;

                    default:
                        n10 = amount / 10;
                        amount = amount % 10;
                        break;
                    }
                    break;

                default:
                    n20 = amount / 20;
                    amount = amount % 20;
                    break;
                }
                break;

            default:
                n50 = amount / 50;
                amount = amount % 50;
                break;
            }
            break;

        default:
            n100 = amount / 100;
            amount = amount % 100;
            break;
        }
    }

    cout << "Notes of 100: " << n100 << endl;
    cout << "Notes of 50: " << n50 << endl;
    cout << "Notes of 20: " << n20 << endl;
    cout << "Notes of 10: " << n10 << endl;
    cout << "Notes of 1: " << n1 << endl;

    return 0;
}
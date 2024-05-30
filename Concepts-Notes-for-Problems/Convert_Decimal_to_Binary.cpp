#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;

    if (n > 0)
    {
        // for positive number
        while (n != 0)
        {
            // checking each bit
            int bit = n & 1;

            // reversing the bit output
            ans = (bit * pow(10, i)) + ans;

            // right shift to remove the checked bit and check next bit
            n = n >> 1;
            i++;
        }

        cout << "Binary representaion is " << ans;
    }
    else
    {
        // for negative number
        int m = n * (-1);
        while (m != 0)
        {
            // checking each bit
            int bit = m & 1;

            // reversing the bit output
            ans = (bit * pow(10, i)) + ans;

            // right shift to remove the checked bit and check next bit
            m = m >> 1;
            i++;
        }
        int newAns = ~(ans);
        newAns = newAns + 1;

        cout
            << "Binary representaion is " << newAns;
    }
}

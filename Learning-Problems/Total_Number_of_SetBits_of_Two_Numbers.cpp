/*

Suppose a & b are inputs, a=2, b=3
then a = 10, b = 11 (in binary)
So the output is 3(1 + 2) set bits

*/

#include <iostream>
#include <math.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1; // Check the least significant bit
        n >>= 1;        // Right shift the number by 1
    }
    return count;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int setBitsA = countSetBits(a);
    int setBitsB = countSetBits(b);

    int totalSetBits = setBitsA + setBitsB;

    cout << "Total set bits in a = " << setBitsA << endl;
    cout << "Total set bits in b = " << setBitsB << endl;
    cout << "Total set bits in a and b = " << totalSetBits << endl;
}
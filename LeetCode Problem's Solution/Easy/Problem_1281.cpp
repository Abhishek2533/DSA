/*

1281. Subtract the Product and Sum of Digits of an Integer

Given an integer number n, return the difference between the product of its digits and the sum of its digits.


Example 1:
Input: n = 123
Output: 6

    Explanation: 
    Product of digits = 2 * 3 * 4 = 24 
    Sum of digits = 2 + 3 + 4 = 9 
    Result = 24 - 9 = 15


Example 2:
Input: n = -123
Output: 0


Example 3:
Input: n = 4421
Output: 21


Constraints: 1 <= n <= 10^5

*/



// SOURCE CODE

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;

        while (n != 0)
        {
            int digit = n % 10;

            prod *= digit;
            sum += digit;

            n = n / 10;
        }

        int ans = prod - sum;
        return ans;
    }
};


/*
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prod = 1;
    int sum = 0;

    while (n != 0)
    {
        int digit = n % 10;

        prod *= digit;
        sum += digit;

        n = n / 10;
    }

    int ans = prod - sum;
    cout << ans;
}

*/
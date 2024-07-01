/*

258. Add Digits

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.


Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0


Constraints: 0 <= num <= 231 - 1


Follow up: Could you do it without any loop/recursion in O(1) runtime?

*/

// SOURCE CODE

class Solution
{
public:
    int sum(int n)
    {
        int siu = 0, ans;
        while (n)
        {
            siu += n % 10;
            n /= 10;
        }
        if (siu > 9)
            ans = sum(siu);

        else
            ans = siu;

        return ans;
    }
    int addDigits(int num)
    {
        return sum(num);
    }
};
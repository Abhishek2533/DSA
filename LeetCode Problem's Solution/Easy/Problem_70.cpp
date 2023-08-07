/*

70. Climbing Stairs


You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:
Input: n = 2
Output: 2
    Explanation: There are two ways to climb to the top.
                 1. 1 step + 1 step
                 2. 2 steps

Example 2:
Input: n = 3
Output: 3
    Explanation: There are three ways to climb to the top.
                 1. 1 step + 1 step + 1 step
                 2. 1 step + 2 steps
                 3. 2 steps + 1 step


Constraints: 1 <= n <= 45

*/



// SOURCE CODE

class Solution
{
public:
    int climbStairs(int n)
    {
        int initial = 0;
        int prev1 = 1;
        int prev2 = 2;
        int curr;

        if (n == 0)
            return initial;
        if (n == 1)
            return prev1;
        if (n == 2)
            return prev2;

        for (int i = 3; i <= n; i++)
        {
            curr = prev1 + prev2;
            initial = prev1;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};
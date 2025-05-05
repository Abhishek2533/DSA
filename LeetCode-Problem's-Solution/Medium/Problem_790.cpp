/*

790. Domino and Tromino Tiling


You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.


Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1


Constraints: 1 <= n <= 1000


*/

// SOURCE CODE





// METHOD 1: RECURSION

class Solution
{
public:
    const int MOD = 1000000007;

    int solve(int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;

        return ((2 * solve(n - 1)) % MOD + (solve(n - 3)) % MOD) % MOD;
    }

    int numTilings(int n)
    {
        return solve(n);
    }
};








// METHOD 2: MEMOIZATION

class Solution
{
public:
    const int MOD = 1000000007;
    int memo[1001];

    int solve(int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;

        if (memo[n] != -1)
            return memo[n];

        return memo[n] = ((2 * solve(n - 1)) % MOD + (solve(n - 3)) % MOD) % MOD;
    }

    int numTilings(int n)
    {
        memset(memo, -1, sizeof(memo));
        return solve(n);
    }
};








// METHOD 3: TABULATION

class Solution
{
public:
    const int MOD = 1000000007;

    int numTilings(int n)
    {
        if (n == 1 || n == 2)
            return n;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((2 * dp[i - 1]) % MOD + (dp[i - 3]) % MOD) % MOD;
        }

        return dp[n];
    }
};
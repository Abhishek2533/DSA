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


// RECURSIVE

class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};




// MEMOIZATION

class Solution {
public:
    vector<int> t;
    Solution(): t(46, -1) {}

    int climbStairs(int n) {
        if(t[n] != -1) return t[n];
        if(n==1 || n==2) return n;
        t[n] = climbStairs(n-1)+climbStairs(n-2);
        return t[n];
    }
};





// BOTTOM - UP

class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};





// BOTTOM - UP (OPTIMIZE)

class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2 || n==3) return n;

        int prev1=3, prev2=2;
        for(int i=4; i<=n; i++) {
            int curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};
/*

198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

// SOURCE CODE

// RECURSIVE ---> TC = O(2^n) , SC = O(n)

class Solution
{
public:
    int f(int idx, vector<int> &nums)
    {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;
        int pick = nums[idx] + f(idx - 2, nums);
        int notPick = 0 + f(idx - 1, nums);
        return max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return f(n - 1, nums);
    }
};

// DP - Memoization ---> TC = O(n) , SC = O(n) + O(n)

class Solution
{
public:
    int f(int idx, vector<int> &dp, vector<int> &nums)
    {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + f(idx - 2, dp, nums);
        int notPick = 0 + f(idx - 1, dp, nums);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n - 1, dp, nums);
    }
};

// DP - Tabulation ---> TC = O(n) , SC = O(n)

class Solution
{
public:
    int f(int n, vector<int> &dp, vector<int> &nums)
    {
        dp[0] = nums[0];

        for (int i = 1; i <= n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n - 1, dp, nums);
    }
};

// DP - Tabulation (Space Optimize) ---> TC = O(n) , SC = O(1)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = 0 + prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
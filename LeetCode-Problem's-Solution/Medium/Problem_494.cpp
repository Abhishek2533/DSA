/*

494. Target Sum


You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.


Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1


Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


*/

// SOURCE CODE


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto s: nums) {
            sum +=s;
        }
        if(target > sum || target < -sum) {
            return 0;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(2*sum + 1, 0));
        int tr = sum ;
        int ntarget = target + tr;

        dp[0][tr - nums[0]] += 1;
        dp[0][tr + nums[0]] += 1;

        for(int i=1; i < nums.size(); i++) {
            for(int k = 0; k <= 2*sum; k++) {
                if(k - nums[i] >= 0) {
                    dp[i][k] +=  dp[i-1][k - nums[i]];
                }
                if(k + nums[i] <= 2*sum) {
                    dp[i][k] +=  dp[i-1][k + nums[i]];
                }
            }
        }

        return dp[nums.size() - 1][ntarget];
    }
};
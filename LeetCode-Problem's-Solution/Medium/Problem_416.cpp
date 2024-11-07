/*

416. Partition Equal Subset Sum


Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100


*/

// SOURCE CODE

class Solution {
public:
    bool subsetSum(vector<int>& nums, long long sum) {
        int n=nums.size();
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
        for(int i=0; i<n; i++){
            t[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                else t[i][j] = t[i - 1][j];
            }
        }
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for(int num : nums) {
            sum+=num;
        }

        if(sum%2 != 0) return false;
        else return subsetSum(nums, sum/2);
    }
};
/*

90. Subsets II


Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/

// SOURCE CODE

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> temp) {
        ans.push_back(temp);
        
        for(int j=i; j<nums.size(); j++) {
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(nums, j+1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, temp);
        return ans;
    }
};
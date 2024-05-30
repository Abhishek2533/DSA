/*

78. Subsets


Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/



// SOURCE CODE

class Solution
{
private:
    void solve(vector<int> nums, vector<int> res, vector<vector<int>> &ans, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(res);
            return;
        }

        solve(nums, res, ans, index + 1); // Exclude nums[i]

        res.push_back(nums[index]); // Include nums[i]
        solve(nums, res, ans, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, res, ans, 0);
        return ans;
    }
};
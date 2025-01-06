/*

40. Combination Sum II


Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.


Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30


*/


// SOURCE CODE


class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& ans) {
        if(target==0) return ans.push_back(curr);

        for(int j=i; j<candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if(candidates[j] > target) break;
            curr.push_back(candidates[j]);
            solve(candidates, target-candidates[j], j+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, curr, ans);
        return ans;
    }
};
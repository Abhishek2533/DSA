/*

2099. Find Subsequence of Length K With the Largest Sum


You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


Example 1:
Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.

Example 3:
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].


Constraints:
1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length


*/


// SOURCE CODE

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n=nums.size();

        for(int i=0; i<n; i++) {
            pq.push({nums[i], i});
            if(pq.size()>k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) res[i] = nums[res[i]];

        return res;
    }
};
/*

2016. Maximum Difference Between Increasing Elements

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
Return the maximum difference. If no such i and j exists, return -1.


Example 1:
Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

Example 2:
Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].

Example 3:
Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.


Constraints:
n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 109

*/


// SOURCE CODE

// METHOD 1:

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    diff = max(diff, nums[j] - nums[i]);
                }
            }
        }

        return diff;
    }
};



// METHOD 2:

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int mn = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] > mn) diff = max({nums[i] - mn, diff});
            if(nums[i] < mn){mn = nums[i];}
        }

        return diff;
    }
};




// METHOD 3:

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<pair<int, int>> st; // {value, index}
        int diff = -1;

        for (int i = 0; i < nums.size(); i++) {
            // Maintain monotonic stack of mins
            if (st.empty() || nums[i] < st.top().first) {
                st.push({nums[i], i});
            }

            // Always compare with the bottom-most (minimum) element
            if (!st.empty() && st.top().second < i && nums[i] > st.top().first) {
                diff = max(diff, nums[i] - st.top().first);
            }
        }

        return diff;
    }
};
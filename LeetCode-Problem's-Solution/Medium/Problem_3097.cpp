/*

3097. Shortest Subarray With OR at Least K II


You are given an array nums of non-negative integers and an integer k.
An array is called special if the bitwise OR of all of its elements is at least k.
Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.


Example 1:
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:
Input: nums = [2,1,8], k = 10
Output: 3
Explanation:
The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:
Input: nums = [1,2], k = 0
Output: 1
Explanation:
The subarray [1] has OR value of 1. Hence, we return 1.


Constraints:
1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109

*/

// SOURCE CODE

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> hash(32, 0);  
        
        int l = 0, r = 0;
        int n = nums.size();
        int num = 0;
        int ans = INT_MAX;

        while (r < n) {
            num |= nums[r];
            
            for (int i = 0; i < 32; i++) {
                if (nums[r] & (1 << i)) {
                    hash[i]++;
                }
            }
            
            while (l <= r && num >= k) {
                ans = min(ans, r - l + 1);
                
                for (int i = 0; i < 32; i++) {
                    if (nums[l] & (1 << i)) {
                        hash[i]--;
                        if (hash[i] == 0) {
                            num -= (1 << i);
                        }
                    }
                }
                l++;
            }
            
            r++;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
/*

2765. Longest Alternating Subarray


You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:
m is greater than 1.
s1 = s0 + 1.
The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.
A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [2,3,4,3,4]
Output: 4
Explanation:
The alternating subarrays are [2, 3], [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.

Example 2:
Input: nums = [4,5,6]
Output: 2
Explanation:
[4,5] and [5,6] are the only two alternating subarrays. They are both of length 2.


Constraints:
2 <= nums.length <= 100
1 <= nums[i] <= 104


*/



//  METHOD -1  -> TC-> O(N^2) || SC -> O(1)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(); // Size of the input vector
        int maxi = -1; // Initialize the maximum length of an alternating subarray as -1
        
        for(int i = 0; i < n-1; i++) { // Outer loop for starting index of subarray
            bool ch = false; // Flag to track increasing or decreasing order
            
            for(int j = i + 1; j < n; j++) { // Inner loop for ending index of subarray
                if(!ch) { // Subarray is in increasing order
                    if(nums[j] - nums[j-1] == 1) { // Check for alternating pattern
                        ch = true; // Set flag to true
                        maxi = max(maxi, j - i + 1); // Update maximum length if necessary
                    } else {
                        break; // Break the inner loop if alternating pattern is not valid
                    }
                } else { // Subarray is in decreasing order
                    if(nums[j] - nums[j-1] == -1) { // Check for alternating pattern
                        ch = false; // Set flag to false
                        maxi = max(maxi, j - i + 1); // Update maximum length if necessary
                    } else {
                        break; // Break the inner loop if alternating pattern is not valid
                    }
                }
            }
        }
        
        return maxi; // Return the maximum length of an alternating subarray
    }
};





//  METHOD -1  -> TC-> O(N) || SC -> O(1)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(),i = 0,j = 1,maxi = -1;
        bool ch = false;
        while(j < n){
            if(!ch){
                if(nums[j] - nums[j-1] == 1){
                    ch = true;
                    maxi = max(maxi,j - i + 1);
                }
                else
                    i = j;
            }
            else{
                if(nums[j] - nums[j-1] == -1){
                    ch = false;
                    maxi = max(maxi,j - i + 1);
                }
                else if(nums[j] - nums[j-1] == 1){
                    i = j - 1;
                    maxi = max(maxi,j - i + 1);
                }
                else{
                    ch = false;
                    i = j;
                }
            }
            j++;
        }
        return maxi;
    }
};
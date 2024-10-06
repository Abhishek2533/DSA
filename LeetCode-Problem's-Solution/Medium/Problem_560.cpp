/*

560. Subarray Sum Equals K


Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2


Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


*/

// SOURCE CODE





// BRUTE FORCE - O(N^3) - TLE

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                long long sum=0;
                for(int x = i; x<=j; x++) {
                    sum+=nums[x];
                }
                if(sum==k) cnt++;
            }
        }
        return cnt;
    }
};






// BETTER - O(N^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++) {
            long long sum=0;
            for(int j=i; j<nums.size(); j++) {
                sum+=nums[j];
                if(sum==k) cnt++;
            }
        }
        return cnt;
    }
};






// OPTIMAL - O(N) | O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        mpp[0]=1;
        long long prefixSum=0; int cnt=0;
        for(int i=0; i<nums.size(); i++) {
            prefixSum+=nums[i];
            int remove = prefixSum-k;
            cnt+=mpp[remove];
            mpp[prefixSum]+=1;
        }
        return cnt;
    }
};
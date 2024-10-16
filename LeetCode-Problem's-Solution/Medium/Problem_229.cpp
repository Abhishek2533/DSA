/*

229. Majority Element II


Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.


Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]


Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?


*/



// SOURCE CODE




// BRUTE FORCE - O(N^2) | O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(ans.size()==0 || ans[0]!=nums[i]) {
                int cnt=0;
                for(int j=0; j<nums.size(); j++) {
                    if(nums[j]==nums[i]) cnt++;
                }
                if(cnt>(nums.size()/3)) ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        return ans;
    }
};




// OPTMIZE - O(N) | O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==(nums.size()/3)+1) ans.push_back(nums[i]);
        }
        return ans;
    }
};




// OPTIMAL - O(2N) | O(!)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0, count2=0, ele1, ele2;

        for(int i=0; i<nums.size(); i++) {
            if(count1==0 && nums[i]!=ele2) {
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1) {
                count2=1;
                ele2=nums[i];
            }
            else if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
            else {
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        int minimum = nums.size()/3 +1;

        count1=0, count2=0;
        for(int i=0; i<nums.size(); i++) {
            if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
        }

        if(count1 >= minimum) ans.push_back(ele1);
        if(count2 >= minimum) ans.push_back(ele2);

        return ans;
    }
};
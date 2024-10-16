/*

18. 4Sum


Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.


Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109


*/


// SOURCE CODE




// OPTIMIZE - O(N^4) | O(quads)X2

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j+1; k<nums.size(); k++) {
                    for(int l=k+1; l<nums.size(); l++) {
                        long long sum = nums[i] + nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};









// OPTIMIZE - O(N^3) | O(N) + O(quads)X2

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                set<long long> hash;
                for(int k=j+1; k<nums.size(); k++) {
                    long long sum = nums[i] + nums[j];
                    sum+=nums[k];
                    int fourth = target - sum;
                    if(hash.find(fourth) != hash.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};






// OPTIMAL -O(N^3) | O(quads)X2

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k=j+1, l=nums.size()-1;
                while(k<l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return st;
    }
};
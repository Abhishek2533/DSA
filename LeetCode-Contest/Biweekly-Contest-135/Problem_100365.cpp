/*

100365. Minimum Array Changes to Make Differences Equal


You are given an integer array nums of size n where n is even, and an integer k.
You can perform some changes on the array, where in one change you can replace any element in the array with any integer in the range from 0 to k.
You need to perform some changes (possibly none) such that the final array satisfies the following condition:
There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).
Return the minimum number of changes required to satisfy the above condition.


Example 1:
Input: nums = [1,0,1,2,4,3], k = 4
Output: 2
Explanation:
We can perform the following changes:
Replace nums[1] by 2. The resulting array is nums = [1,2,1,2,4,3].
Replace nums[3] by 3. The resulting array is nums = [1,2,1,3,4,3].
The integer X will be 2.

Example 2:
Input: nums = [0,1,2,3,3,6,5,4], k = 6
Output: 2
Explanation:
We can perform the following operations:
Replace nums[3] by 0. The resulting array is nums = [0,1,2,0,3,6,5,4].
Replace nums[4] by 4. The resulting array is nums = [0,1,2,0,4,6,5,4].
The integer X will be 4.


Constraints:
2 <= n == nums.length <= 105
n is even.
0 <= nums[i] <= k <= 105


*/

// SOURCE CODE

class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        map<int, vector<int>> mp;
        vector<int> v;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int a = nums[i], b = nums[nums.size() - i - 1];
            int diff = abs(a - b);
            int X = max({a, b, k - a, k - b});
            mp[diff].push_back(X);
            v.push_back(X);
        }
        int ans = nums.size();
        sort(v.begin(), v.end());

        for (auto &val : mp)
        {

            int diff = val.first;
            int res = lower_bound(v.begin(), v.end(), diff) - v.begin();
            res = res * 2 + (nums.size() / 2 - res);

            for (auto &X : val.second)
            {
                if (X < diff)
                {
                    res -= 2;
                }
                else
                {
                    res -= 1;
                }
            }

            ans = min(ans, res);
        }

        return ans;
    }
};
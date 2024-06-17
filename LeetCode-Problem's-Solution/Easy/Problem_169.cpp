/*

169. Majority Element


The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

*/

// SOURCE CODE

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int element = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                element = nums[i];
                count = 1;
            }
            else if (element == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == element)
                cnt1++;
        }

        if (cnt1 > (nums.size() / 2))
            return element;
        return -1;
    }
};
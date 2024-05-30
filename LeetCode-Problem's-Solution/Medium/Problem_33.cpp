/*

33. Search in Rotated Sorted Array


There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 0

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1


Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4

*/



// SOURCE CODE

class Solution
{
public:
    int getPivot(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e)
        {
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int binarySearch(vector<int> &nums, int s, int e, int target)
    {
        int start = s;
        int end = e;
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            if (nums[mid] == target)
            {
                return mid;
            }

            else if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = getPivot(nums);
        if (target >= nums[pivot] && target <= nums[n - 1])
        {
            return binarySearch(nums, pivot, n - 1, target);
        }
        else
        {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
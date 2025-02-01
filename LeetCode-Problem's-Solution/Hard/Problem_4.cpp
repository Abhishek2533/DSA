/*

4. Median of Two Sorted Arrays


Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106


*/


// SOURCE CODE

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int n=n1+n2;
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);

        int left=(n1+n2+1)>>1;
        int low=0, high=n1;

        while(low<=high) {
            int mid1=(low+high)>>1;
            int mid2=left-mid1;
            
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1<=r2 && l2<=r1) {
                if(n%2==1) return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2))/2.0;
            } else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};
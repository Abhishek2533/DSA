/*

1901. Find a Peak Element II


A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.


Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.


Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.

*/

// SOURCE CODE

class Solution
{
public:
    int maxElement(vector<vector<int>> &mat, int row, int mid)
    {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < row; i++)
        {
            if (mat[i][mid] > maxValue)
            {
                maxValue = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = maxElement(mat, n, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};
            else if (mat[row][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};
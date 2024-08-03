/*

Q3. Minimum Number of Flips to Make Binary Grid Palindromic II

You are given an m x n binary matrix grid.
A row or column is considered palindromic if its values read the same forward and backward.
You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.


Example 1:
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 3
Explanation:


Example 2:
Input: grid = [[0,1],[0,1],[0,0]]
Output: 2
Explanation:


Example 3:
Input: grid = [[1],[1]]
Output: 2
Explanation:



Constraints:
m == grid.length
n == grid[i].length
1 <= m * n <= 2 * 105
0 <= grid[i][j] <= 1


*/

// SOURCE CODE

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        if (n % 2 == 1 && m % 2 == 1)
        {
            if (grid[n / 2][m / 2] == 1)
            {
                ans += 1;
            }
        }

        vector<int> minFlipRequired(3, 0);
        if (n % 2 == 1)
        {
            int a = 0, b = m - 1;
            while (a < b)
            {
                int sm = grid[n / 2][a] + grid[n / 2][b];
                minFlipRequired[sm] += 1;
                a += 1;
                b -= 1;
            }
        }

        if (m % 2 == 1)
        {
            int x = 0, y = n - 1;
            while (x < y)
            {
                int sum = grid[x][m / 2] + grid[y][m / 2];
                minFlipRequired[sum] += 1;
                x += 1;
                y -= 1;
            }
        }

        if (minFlipRequired[2] % 2 == 1)
        {
            if (minFlipRequired[1] > 0)
            {
                ans += minFlipRequired[1];
            }
            else
            {
                ans += 2;
            }
        }
        else
        {
            ans += minFlipRequired[1];
        }

        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < m / 2; ++j)
            {
                int a = grid[i][j];
                int b = grid[n - 1 - i][j];
                int c = grid[i][m - 1 - j];
                int d = grid[n - 1 - i][m - 1 - j];

                int sum = a + b + c + d;

                if (sum != 0 && sum != 4)
                {
                    ans += min(sum, 4 - sum);
                }
            }
        }

        return ans;
    }
};
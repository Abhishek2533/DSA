/*

100359. Count Submatrices With Equal Frequency of X and Y

Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contains:
grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.

Example 1:
Input: grid = [["X","Y","."],["Y",".","."]]
Output: 3
Explanation:

Example 2:
Input: grid = [["X","X"],["X","Y"]]
Output: 0
Explanation:
No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:
Input: grid = [[".","."],[".","."]]
Output: 0
Explanation:
No submatrix has at least one 'X'.

Constraints:
1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.


*/

// SOURCE CODE

class Solution
{
private:
    void computeSums(const vector<vector<char>> &grid, vector<vector<int>> &prefixX, vector<vector<int>> &prefixY)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= cols; ++j)
            {
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] - prefixX[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] - prefixY[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }
    }

    bool isValidMatrix(int xCount, int yCount, char first)
    {
        return (xCount == yCount && xCount > 0 && (first == 'X' || first == 'Y' || first == '.'));
    }

    int countValidSubmatrices(const vector<vector<int>> &prefixX, const vector<vector<int>> &prefixY, const vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;

        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= cols; ++j)
            {
                int xCount = prefixX[i][j];
                int yCount = prefixY[i][j];

                if (isValidMatrix(xCount, yCount, grid[0][0]))
                {
                    ++cnt;
                }
            }
        }

        return cnt;
    }

public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> CountX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> CountY(rows + 1, vector<int>(cols + 1, 0));

        computeSums(grid, CountX, CountY);

        return countValidSubmatrices(CountX, CountY, grid);
    }
};
/*

1931. Painting a Grid With Three Different Colors


You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.


Example 1:
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:
Input: m = 5, n = 5
Output: 580986


Constraints:
1 <= m <= 5
1 <= n <= 1000


*/

// SOURCE CODE






// METHOD 1: Recursion

class Solution
{
public:
    vector<string> columnStates;
    int M = 1e9 + 7;

    int solve(int remColors, int prevIdx, int m)
    {
        if (remColors == 0)
            return 1;

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++)
        {
            if (i == prevIdx)
                continue;

            string currState = columnStates[i];
            bool valid = true;

            for (int j = 0; j < m; j++)
            {
                if (prevState[j] == currState[j])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ways = (ways + solve(remColors - 1, i, m)) % M;
        }

        return ways;
    }

    void generateColumnStates(string curr, char prevColor, int l, int m)
    {
        if (l == m)
        {
            columnStates.push_back(curr);
            return;
        }

        for (char ch : {'R', 'G', 'B'})
        {
            if (ch == prevColor)
                continue;
            generateColumnStates(curr + ch, ch, l + 1, m);
        }
    }

    int colorTheGrid(int m, int n)
    {
        generateColumnStates("", '#', 0, m);

        int res = 0;
        for (int i = 0; i < columnStates.size(); i++)
        {
            res = (res + solve(n - 1, i, m)) % M;
        }

        return res;
    }
};









// METHOD 2: Memoization

class Solution
{
public:
    vector<string> columnStates;
    vector<vector<int>> t;
    int M = 1e9 + 7;

    int solve(int remColors, int prevIdx, int m)
    {
        if (remColors == 0)
            return 1;

        if (t[remColors][prevIdx] != -1)
            return t[remColors][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++)
        {
            if (i == prevIdx)
                continue;

            string currState = columnStates[i];
            bool valid = true;

            for (int j = 0; j < m; j++)
            {
                if (prevState[j] == currState[j])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ways = (ways + solve(remColors - 1, i, m)) % M;
        }

        return t[remColors][prevIdx] = ways;
    }

    void generateColumnStates(string curr, char prevColor, int l, int m)
    {
        if (l == m)
        {
            columnStates.push_back(curr);
            return;
        }

        for (char ch : {'R', 'G', 'B'})
        {
            if (ch == prevColor)
                continue;
            generateColumnStates(curr + ch, ch, l + 1, m);
        }
    }

    int colorTheGrid(int m, int n)
    {
        generateColumnStates("", '#', 0, m);

        int totalStates = columnStates.size();
        t = vector<vector<int>>(n + 1, vector<int>(totalStates + 1, -1));

        int res = 0;
        for (int i = 0; i < columnStates.size(); i++)
        {
            res = (res + solve(n - 1, i, m)) % M;
        }

        return res;
    }
};
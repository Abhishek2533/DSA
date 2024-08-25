/*

547. Number of Provinces


There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.


Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]


*/

// SOURCE CODE

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adjLs, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adjLs[node])
        {
            if (!visited[it])
            {
                dfs(it, adjLs, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        if (isConnected.empty())
            return 0;
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, adjLs, visited);
            }
        }
        return cnt;
    }
};
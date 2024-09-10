//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(char u, unordered_map<char, vector<char>> &adjList, unordered_map<int, bool> &vis)
    {
        vis[u] = true;

        for (auto v : adjList[u])
        {
            if (!vis[v])
            {
                dfs(v, adjList, vis);
            }
        }
    }
    int isCircle(vector<string> &arr)
    {
        // code here

        // initialize a adjacency list
        unordered_map<char, vector<char>> adjList;

        // traverse and create adjacency list
        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][arr[i].size() - 1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // initialize visited array
        unordered_map<int, bool> vis;

        // to check if connected components are more than 1
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!vis[arr[i][0]])
            {
                dfs(arr[i][0], adjList, vis);
                cnt++;
            }
        }

        // chacking for odd degree
        int degree = 0;
        for (auto i : adjList)
        {
            if (adjList[i.first].size() & 1)
                degree++;
        }

        // if there is more than 1 connected component OR if there is an odd degree,
        // then it cannot be possible to have EUCLERIAN circuit -> return false
        if (cnt > 1 || degree != 0)
            return 0;
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
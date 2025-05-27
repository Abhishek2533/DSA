/*

Company Tags:

        Amazon
        Microsoft
        OYO Rooms


*/


class Solution {
  public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int c, int d) {
        visited[u] = true;
        for (int v : adj[u]) {
            if ((u == c && v == d) || (u == d && v == c)) continue; // Skip the edge (c, d)
            if (!visited[v]) {
                dfs(v, adj, visited, c, d);
            }
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        // Step 2: Run DFS from c, skipping the edge (c, d)
        vector<bool> visited(V, false);
        dfs(c, adj, visited, c, d);
    
        // Step 3: If d is not visited, (c, d) is a bridge
        return !visited[d];
    }
};
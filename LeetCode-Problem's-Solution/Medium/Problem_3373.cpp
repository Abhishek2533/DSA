/*

3372. Maximize the Number of Target Nodes After Connecting Trees I


There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.


Example 1:
Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
Output: [8,7,7,8,8]
Explanation:
For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 4 from the second tree.
For i = 2, connect node 2 from the first tree to node 7 from the second tree.
For i = 3, connect node 3 from the first tree to node 0 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:
Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
Output: [3,6,6,6,6]
Explanation:
For every i, connect node i of the first tree with any node of the second tree.


Constraints:
2 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.


*/


// SOURCE CODE



class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, int parentNode, vector<int>& arr, int &even, int &odd){
        if(arr[u] == 0) even++;
        else odd++;

        for(int neighbour : adj[u]) if(neighbour != parentNode){
            arr[neighbour] = arr[u]^1;
            dfs(adj, neighbour, u, arr, even, odd);
        }
    }

    void buildAdj(vector<vector<int>>& edges, unordered_map<int, vector<int>>& adj) {
        for(auto& edge : edges) {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;

        buildAdj(edges1, adj1);
        buildAdj(edges2, adj2);

        vector<int> arr1(n, -1);
        vector<int> arr2(m, -1);

        int even1=0, odd1=0, even2=0, odd2=0;

        arr1[0] = 0;
        dfs(adj1, 0, -1, arr1, even1, odd1);
        arr2[0] = 0;
        dfs(adj2, 0, -1, arr2, even2, odd2);
        int maxCount = max(even2, odd2);
        
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            res[i] = (arr1[i] == 0 ? even1 : odd1) + maxCount;
        }

        return res;
    }
};
/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        Samsung
        Ola Cabs
        Adobe
        SAP Labs


*/


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto&k:adj[node]){
                if(!vis[k]){
                    vis[k]=1;
                    q.push(k);
                }
            }
        }
        return res;
    }
};
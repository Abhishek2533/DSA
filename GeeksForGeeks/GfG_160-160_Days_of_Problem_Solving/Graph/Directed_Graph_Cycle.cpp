/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        Samsung
        MakeMyTrip
        Oracle
        Goldman Sachs
        Adobe
        BankBazaar
        Rockstand


*/


class Solution {
  public:
    bool canTopoSort(int V, vector<vector<int>> edges) {
        vector<vector<int>> graph(V);
        vector<int> incount(V, 0);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            incount[edge[1]] += 1;
        }
        queue<int> nodes; 
        for(int i=0;i<V;i++) {
            if(incount[i] == 0) nodes.push(i);
        }
        vector<int> ans;
        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            ans.push_back(node);
            for(auto next: graph[node]) {
                incount[next] -= 1;
                if(incount[next] == 0) nodes.push(next);
            }
        }
        return (int) ans.size() == V;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        return !canTopoSort(V, edges);
    }
};
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findDist(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int, vector<int>>> heap;
        for(int i=0; i<points.size(); i++) {
            int dist = findDist(points[i]);
            
            if(heap.size()<k) {
                heap.push({dist, points[i]});
            } else {
                if(dist < heap.top().first) {
                    heap.pop();
                    heap.push({dist, points[i]});
                }
            }
        }
        
        vector<vector<int>> res;
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
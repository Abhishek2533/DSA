/*

Company Tags:

        Accolite
        Amazon
        Microsoft
        D-E-Shaw
        Visa
        MAQ Software
        Amdocs
        Twitter

      
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& res, vector<bool>& rows, vector<bool>& diagUp, vector<bool>& diagDown) {
        if(col>n) return res.push_back(board);
        
        for(int i=1; i<=n; i++) {
            if(!rows[i] && !diagUp[i-col+n] && !diagDown[i+col]) {
                board.push_back(i);
                rows[i]=true;
                diagUp[i-col+n]=true;
                diagDown[i+col]=true;
                
                solve(col+1, n, board, res, rows, diagUp, diagDown);
                
                board.pop_back();
                rows[i]=false;
                diagUp[i-col+n]=false;
                diagDown[i+col]=false;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> board;
        vector<vector<int>> res;
        vector<bool> rows(n+1, false);
        vector<bool> diagUp(2*n+1, false);
        vector<bool> diagDown(2*n+1, false);
        
        solve(1, n, board, res, rows, diagUp, diagDown);
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
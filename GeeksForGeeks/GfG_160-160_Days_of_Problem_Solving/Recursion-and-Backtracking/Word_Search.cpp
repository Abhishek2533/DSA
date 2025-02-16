/*

Company Tags:

        Amazon
        Microsoft
        Intuit
        Apple


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool search(vector<vector<char>>& mat, string& word, int row, int col, int idx, int n, int m) {
        if(idx==word.length()) return true;
        if(row<0 || col<0 || row==n || col==m || mat[row][col]!=word[idx] || mat[row][col]=='#') return false;
        
        char c=mat[row][col];
        mat[row][col]='#';
        
        bool top=search(mat, word, row-1, col, idx+1, n, m);
        bool right=search(mat, word, row, col+1, idx+1, n, m);
        bool down=search(mat, word, row+1, col, idx+1, n, m);
        bool left=search(mat, word, row, col-1, idx+1, n, m);
        
        mat[row][col]=c;
        
        return top || right || down || left;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n=mat.size(), m=mat[0].size();
        int idx=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==word[idx]) if(search(mat, word, i, j, idx, n, m)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
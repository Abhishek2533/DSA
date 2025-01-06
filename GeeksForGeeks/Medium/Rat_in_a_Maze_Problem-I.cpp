//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>>& visited, string& temp, vector<string>& ans) {
        if(i<0 || i>=n || j<0 || j>=n || mat[i][j]==0 || visited[i][j]==1) return;
        if(i==n-1 && j==n-1) return ans.push_back(temp);
        
        visited[i][j]=1;
        
        temp+="D";
        solve(i+1, j, n, mat, visited, temp, ans);
        temp.pop_back();
        
        temp+="U";
        solve(i-1, j, n, mat, visited, temp, ans);
        temp.pop_back();
        
        temp+="R";
        solve(i, j+1, n, mat, visited, temp, ans);
        temp.pop_back();
        
        temp+="L";
        solve(i, j-1, n, mat, visited, temp, ans);
        temp.pop_back();
        
        visited[i][j]=-1;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        string temp="";
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n,-1));
        
        if (mat[0][0]==0 || mat[n-1][n-1]==0) return ans;
            
        solve(0, 0, n, mat, visited, temp, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
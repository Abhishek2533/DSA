/*

Company Tags:

        Zoho
        Flipkart
        Amazon
        Microsoft
        MakeMyTrip
        Ola Cabs
        Oracle
        MAQ Software
        Directi
        PayPal
        Samsung


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<vector<int>>& mat, int row, int col, int val) {
        for(int i=0; i<9; i++) {
            if(mat[i][col]==val) return false;
            if(mat[row][i]==val) return false;
            if(mat[3*(row/3)+i / 3][3*(col/3)+i %3]==val) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat.size(); j++) {
                if(mat[i][j]==0) {
                    for(int k=1; k<=9; k++) {
                        if(isValid(mat, i, j, k)) {
                            mat[i][j]=k;
                            if(solve(mat)) return true;
                            else mat[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
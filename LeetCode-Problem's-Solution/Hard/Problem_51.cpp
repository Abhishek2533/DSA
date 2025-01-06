/*

51. N-Queens


The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]


Constraints: 1 <= n <= 9


*/


// SOURCE CODE


// RECURSIVE CODE - BRUTE FORCE

class Solution {
public:
    // function to check placing the queen is safe or not
    bool isSafeToPlace(int row, int col, int n, vector<string>& temp) {
        // check for upper diagonal queen intersection
        int dupRow = row;
        int dupCol = col;

        while(dupRow>=0 && dupCol>=0) {
            if(temp[dupRow][dupCol] == 'Q') return false;
            dupRow--, dupCol--;
        }

        // check for in-row queen intersection
        dupRow = row;
        dupCol = col;

        while(dupCol>=0) {
            if(temp[dupRow][dupCol] == 'Q') return false;
            dupCol--;
        }

        // check for lower diagonal queen intersection
        dupRow = row;
        dupCol = col;

        while(dupRow<n && dupCol>=0) {
            if(temp[dupRow][dupCol] == 'Q') return false;
            dupRow++, dupCol--;
        }

        return true;
    }

    // recursive function to find possible solution
    void solve(int col, int n, vector<string>& temp, vector<vector<string>>& ans) {
        if(col==n) return ans.push_back(temp);

        // loop through row
        for(int row=0; row<n; row++) {
            if(isSafeToPlace(row, col, n, temp)) {
                temp[row][col]='Q';
                solve(col+1, n, temp, ans);
                temp[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;     // [[], [], [], []]
        vector<string> temp(n);         // temp = [ , , , ]
        string s(n, '.');               // s = "...."
        for (int i = 0; i < n; i++) {
            temp[i] = s;                // temp = ["....", "....", "....", "...."]
        }
        solve(0, n, temp, ans);
        return ans;
    }
};




// RECURSIVE CODE - OPTIMIZE (USING HASHING)

class Solution {
public:
    // recursive function to find possible solution
    void solve(int col, int n, vector<int>& leftRowCheck, vector<int>& upperDiagonalCheck, vector<int>& lowerDiagonalCheck, vector<string>& temp, vector<vector<string>>& ans) {
        if(col==n) return ans.push_back(temp);

        // loop through row
        for(int row=0; row<n; row++) {
            // check in hashing for row, upper diagonal and lower diagonal
            int upperDiagIndex = n - 1 + col - row;
            int lowerDiagIndex = row + col;
            
            if(leftRowCheck[row]==0 && upperDiagonalCheck[upperDiagIndex]==0 && lowerDiagonalCheck[lowerDiagIndex]==0) {
                temp[row][col]='Q';
                leftRowCheck[row] = 1;
                upperDiagonalCheck[upperDiagIndex] = 1;
                lowerDiagonalCheck[lowerDiagIndex] = 1;
                solve(col+1, n, leftRowCheck, upperDiagonalCheck, lowerDiagonalCheck, temp, ans);
                temp[row][col]='.';
                leftRowCheck[row] = 0;
                upperDiagonalCheck[upperDiagIndex] = 0;
                lowerDiagonalCheck[lowerDiagIndex] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;     // [[], [], [], []]
        vector<string> temp(n, string(n, '.'));  // temp = ["....", "....", "....", "...."]
        vector<int> leftRowCheck(n, 0);
        vector<int> upperDiagonalCheck(2*n-1, 0);
        vector<int> lowerDiagonalCheck(2*n-1, 0);
        solve(0, n, leftRowCheck, upperDiagonalCheck, lowerDiagonalCheck, temp, ans);
        return ans;
    }
};
/*

79. Word Search


Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?

*/


// SOURCE CODE


class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int row, int col, int k) {
        if (k == word.size()) return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[k]) return false;

        char temp = board[row][col];
        board[row][col] = '#';

        if (solve(board, word, row - 1, col, k + 1) ||  // Up
            solve(board, word, row + 1, col, k + 1) ||  // Down
            solve(board, word, row, col - 1, k + 1) ||  // Left
            solve(board, word, row, col + 1, k + 1))    // Right
            return true;

        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (solve(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};

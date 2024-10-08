/*

118. Pascal's Triangle


Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]


Constraints: 1 <= numRows <= 30


*/


// SOURCE CODE


class Solution {
public:
    vector<int> nCr(int n) {
        long long res = 1;
        vector<int> temp;
        temp.push_back(1);
        for (int i = 1; i < n; i++) {
            res = res * (n - i);
            res = res / i;
            temp.push_back(res);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(nCr(i));
        }
        return ans;
    }
};
/*

Company Tags:

        Flipkart
        Microsoft
        FactSet


*/


// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j) {
        if(i+1==j) return 0;
        
        int res=INT_MAX;
        
        for(int k=i+1; k<j; k++) {
            int curr=solve(arr, i, k)+solve(arr, k, j)+arr[i]*arr[k]*arr[j];
            res=min(res, curr);
        }
        
        return res;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        return solve(arr, 0, n-1);
    }
};








// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(i+1==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res=INT_MAX;
        
        for(int k=i+1; k<j; k++) {
            int curr=solve(arr, i, k, dp)+solve(arr, k, j, dp)+arr[i]*arr[k]*arr[j];
            res=min(res, curr);
        }
        
        return dp[i][j]=res;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 0, n-1, dp);
    }
};
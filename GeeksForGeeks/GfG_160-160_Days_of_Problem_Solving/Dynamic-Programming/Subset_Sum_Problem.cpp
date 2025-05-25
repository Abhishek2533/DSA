/*

Company Tags:

        Amazon
        Microsoft


*/


// METHOD 1: RECURSION

class Solution {
  public:
    bool subset(vector<int>& arr, int sum, int n) {
        if(sum==0) return true;
        if(n==0) return false;
        
        return subset(arr, sum, n-1) || subset(arr, sum-arr[n-1], n-1);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return subset(arr, sum, arr.size());
    }
};






// METHOD 2: MEMOIZATION

class Solution {
  public:
    bool subset(vector<int>& arr, int sum, int n, vector<vector<int>>& dp) {
        if(sum==0) return 1;
        if(n==0) return 0;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(arr[n-1]>sum) return subset(arr, sum, n-1, dp);
        else return dp[n][sum] = subset(arr, sum, n-1, dp) || subset(arr, sum-arr[n-1], n-1, dp);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        return subset(arr, sum, arr.size(), dp);
    }
};






// METHOD 3: TABULATION

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, false));
        
        for(int i=0; i<=n; i++) dp[i][0]=true;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};
/*

Company Tags:

        Accolite
        Amazon
        Microsoft
        OYO Rooms
        Adobe
        Drishti-Soft


*/



// METHOD 1: RECURSION

class Solution {
  public:
    bool subsetSum(vector<int>& arr, int sum, int n) {
        if(sum==0) return true;
        if(n==0) return false;
        
        if(arr[n-1]>sum) return subsetSum(arr, sum, n-1);
        
        return subsetSum(arr, sum, n-1) || subsetSum(arr, sum-arr[n-1], n-1);
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        
        if(sum%2!=0)  return false;
        return subsetSum(arr, sum/2, arr.size());
    }
};





// METHOD 2: MEMOIZATION

class Solution {
  public:
    bool subsetSum(vector<int>& arr, int sum, int n, vector<vector<int>>& dp) {
        if(sum==0) return 1;
        if(n==0) return 0;
        if(dp[n-1][sum] != -1) return dp[n-1][sum];
        
        if(arr[n-1]>sum) return dp[n-1][sum] = subsetSum(arr, sum, n-1, dp);
        
        return dp[n-1][sum] = subsetSum(arr, sum, n-1, dp) || subsetSum(arr, sum-arr[n-1], n-1, dp);
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        
        if(sum%2!=0)  return false;
        
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        return subsetSum(arr, sum/2, arr.size(), dp);
    }
};







// METHOD 3: TABULATION

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        int n=arr.size();
        
        if(sum%2!=0)  return false;
        
        sum/=2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i=0; i<=n; i++) dp[i][0]=true;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};
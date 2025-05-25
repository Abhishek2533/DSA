/*

Company Tags:

        Paytm
        Flipkart
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        OYO Rooms
        Samsung
        Snapdeal
        Zoho


*/


// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int n) {
        if(sum==0) return 1;
        if(sum<0 || n==0) return 0;
        
        return solve(coins, sum-coins[n-1], n) + solve(coins, sum, n-1);
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        return solve(coins, sum, n);
    }
};




// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int n, vector<vector<int>>& dp) {
        if(sum==0) return 1;
        if(sum<0 || n==0) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];
        
        return dp[n][sum] = solve(coins, sum-coins[n-1], n, dp) + solve(coins, sum, n-1, dp);
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(coins, sum, n, dp);
    }
};




// METHOD 3: TABULATION

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        dp[0][0]=1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                dp[i][j] += dp[i-1][j];
                
                if(j >= coins[i-1]) {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};
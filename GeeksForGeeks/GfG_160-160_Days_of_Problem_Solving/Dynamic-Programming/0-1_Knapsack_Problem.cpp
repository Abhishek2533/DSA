/*

Company Tags:

        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        Snapdeal
        Oracle
        Payu
        Visa
        Directi
        GreyOrange
        Mobicip


*/


// METHOD 1: RECURSION

class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int n) {
        if(n==0 || W==0) return 0;
        
        int pick=0;
        if(wt[n-1]<=W) pick = val[n-1] + solve(W-wt[n-1], val, wt, n-1);
        
        int not_pick = solve(W, val, wt, n-1);
        
        return max(pick, not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        return solve(W, val, wt, val.size());
    }
};




// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>>& dp) {
        if(n==0 || W==0) return 0;
        if(dp[n][W] != -1) return dp[n][W];
        
        int pick=0;
        if(wt[n-1]<=W) pick = val[n-1] + solve(W-wt[n-1], val, wt, n-1, dp);
        
        int not_pick = solve(W, val, wt, n-1, dp);
        
        return dp[n][W] = max(pick, not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        return solve(W, val, wt, n, dp);
    }
};



// METHOD 3: TABULATION

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=W; j++) {
                if(i==0 || j==0) dp[i][j]=0;
                else {
                    int pick=0;
                    if(wt[i-1]<=j) pick = val[i-1] + dp[i-1][j-wt[i-1]];
                    
                    int not_pick=dp[i-1][j];
                    
                    dp[i][j]=max(pick, not_pick);
                }
            }
        }
        
        return dp[n][W];
    }
};
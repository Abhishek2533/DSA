/*

Company Tags:

        Paytm
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        Samsung
        Snapdeal
        Oracle
        Visa
        Google
        Synopsys


*/


// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i) {
        if(sum==0) return 0;
        if(sum<0 || i==coins.size()) return INT_MAX;
        
        int take=INT_MAX;
        if(coins[i]>0) {
            take=solve(coins, sum-coins[i], i);
            if(take!=INT_MAX) take++;
        }
        
        int not_take=solve(coins, sum, i+1);
        
        return min(take, not_take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int res=solve(coins, sum, 0);
        
        return res == INT_MAX ? -1 : res;
    }
};





// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp) {
        if(sum==0) return 0;
        if(sum<0 || i==coins.size()) return INT_MAX;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take=INT_MAX;
        if(coins[i]>0) {
            take=solve(coins, sum-coins[i], i, dp);
            if(take!=INT_MAX) take++;
        }
        
        int not_take=solve(coins, sum, i+1, dp);
        
        return dp[i][sum] = min(take, not_take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, -1));
        int res=solve(coins, sum, 0, dp);
        
        return res == INT_MAX ? -1 : res;
    }
};






// METHOD 3: TABULATION

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, 0));
        
        for(int i=coins.size()-1; i>=0; i--) {
            for(int j=1; j<=sum; j++) {
                dp[i][j] = INT_MAX;
                
                int take=INT_MAX;
                int not_take=INT_MAX;
                
                if(j-coins[i] >= 0)  {
                    take = dp[i][j-coins[i]];
                    if(take!=INT_MAX) take++;
                }
                
                if(i+1 < coins.size()) not_take=dp[i+1][j];
                
                dp[i][j] = min(take, not_take);
            }
        }
        
        if(dp[0][sum] != INT_MAX) return dp[0][sum];
        return -1;
    }
};
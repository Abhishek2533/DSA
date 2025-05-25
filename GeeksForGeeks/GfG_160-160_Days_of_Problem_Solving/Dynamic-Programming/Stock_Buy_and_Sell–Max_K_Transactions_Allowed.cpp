/*

Company Tags:

        Accolite
        Amazon
        Microsoft


*/



// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& prices, int i, int k, bool buy) {
        if(k<=0 || i>=prices.size()) return 0;
        
        int res=0, profit=0;
        
        if(buy) {
            profit=solve(prices, i+1, k, 0) - prices[i];
            res=max(res, profit);
        } else {
            profit = prices[i] + solve(prices, i+1, k-1, 1);
            res=max(res, profit);
        }
        
        profit = solve(prices, i+1, k, buy);
        return res=max(res, profit);
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        return solve(prices, 0, k, 1);
    }
};








// METHOD 2: MEMOIZATION


class Solution {
  public:
    int solve(vector<int>& prices, int i, int k, int buy, vector<vector<vector<int>>>& dp) {
        if(k<=0 || i>=prices.size()) return 0;
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        
        int res=0, profit=0;
        
        if(buy) {
            profit=solve(prices, i+1, k, 0, dp) - prices[i];
            res=max(res, profit);
        } else {
            profit = prices[i] + solve(prices, i+1, k-1, 1, dp);
            res=max(res, profit);
        }
        
        profit = solve(prices, i+1, k, buy, dp);
        res=max(res, profit);
        return dp[i][k][buy]=res;
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3, -1)));
        return solve(prices, 0, k, 1, dp);
    }
};









// METHOD 3: TABULATION

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        
        for(int i=n-1; i>=0; i--) {
            for(int l=1; l<=k; l++) {
                dp[i][l][1]=max(dp[i+1][l][0]-prices[i], dp[i+1][l][1]);
                dp[i][l][0]=max(prices[i]+dp[i+1][l-1][1], dp[i+1][l][0]);
            }
        }
        
        return dp[0][k][1];
    }
};